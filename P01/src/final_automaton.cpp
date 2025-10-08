/**
  * Universidad de La Laguna 
  * Escuela Superior de Ingeniería y Tecnología 
  * Grado en Ingeniería Informática 
  * Complejidad Computacional
  * 
  * @author Paulo Padilla Domingues 
  * @date Sep 25 2025 
  * @brief
  * 
  * Archivo 
  * Historial de revisiones
  *     // 
*/
#include "../include/final_automaton.hpp"
#include <fstream>
#include <sstream>

/**
 * @brief Serialize a copy of the stack.
 * @param stackCopy The stack to serialize.
 * @return A string representation of the stack.
 */
static std::string SerializeStackCopy(Stack<char> stackCopy) {
  std::string string;
  while (!stackCopy.IsEmpty()) {
    string.push_back(stackCopy.Pop()); // Pop devuelve el top
  }
  return string;
}

/**
 * @brief Get a state by its ID.
 * @param id The ID of the state.
 * @return The state with the given ID.
 */
State FinalAutomaton::GetStateByID(const std::string& id) const {
  State key(id);
  auto it = states_.find(key);
  if (it == states_.end()) throw std::out_of_range("State not found: " + id);
  return *it;
}

/**
 * @brief Constructor for the FinalAutomaton class.
 * @param input_file Path to the input file.
 */
FinalAutomaton::FinalAutomaton(const std::string& input_file) {
  std::ifstream file(input_file);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open input file");
  }
  std::string line;
  int counter = 0;
  while (std::getline(file, line)) {
    // Comments
    if (line[0] == '#') continue;
    std::stringstream flujo(line);

    // States in the automaton
    if (counter == 0) {
      std::string state;
      while (flujo >> state) {
        State new_state(state);
        this->states_.emplace(new_state);
      }
      counter++;
      continue;
    }

    // Symbols in the automaton
    if (counter == 1) {
      std::string symbol;
      while (flujo >> symbol) {
        if (symbol.size() > 1) {
          throw std::runtime_error("Symbol too long");
        } 
        Symbol new_symbol(symbol[0]);
        this->alphabet_.AddSymbol(new_symbol);
      }
      counter++;
      continue;
    }

    // Stack symbols in the automaton
    if (counter == 2) {
      std::string stack_symbol;
      while (flujo >> stack_symbol) {
        if (stack_symbol.size() > 1) {
          throw std::runtime_error("Stack symbol too long");
        }
        Symbol new_stack_symbol(stack_symbol[0]);
        this->stack_alphabet_.AddSymbol(new_stack_symbol);
      }
      counter++;
      continue;
    }

    // Initial state in the automaton
    if (counter == 3) {
      std::string initial_state;
      if (flujo >> initial_state) {
        if (this->states_.find(initial_state) == this->states_.end()) {
          throw std::runtime_error("Initial state not in state set");
        }
        this->initial_state_ = State(initial_state);
      } else throw std::runtime_error("Failed to read initial state");
      counter++;
      continue;
    }

    // Initial symbol stack in the automaton
    if (counter == 4) {
      std::string initial_symbol_stack;
      if (flujo >> initial_symbol_stack) {
        if (initial_symbol_stack.size() > 1) throw std::runtime_error("Initial symbol stack too long");
        Symbol new_initial_symbol_stack(initial_symbol_stack[0]);
        if (this->stack_alphabet_.IsSymbolPresent(new_initial_symbol_stack)) {
          this->stack_.Push(initial_symbol_stack[0]);
          this->initial_stack_symbol_ = initial_symbol_stack[0];
        } else throw std::runtime_error("Initial symbol stack not in stack alphabet");
      } else throw std::runtime_error("Failed to read initial symbol stack");
      counter++;
      continue;
    }

    // Final state in the automaton
    if (counter == 5) {
      std::string final_state;
      if (flujo >> final_state) {
        if (this->states_.find(final_state) == this->states_.end()) {
          throw std::runtime_error("Final state not in state set");
        }
        this->final_state_ = State(final_state);
      } else throw std::runtime_error("Failed to read final state");
      counter++;
      continue;
    }
    
    // Transition rules in the automaton
    if (counter == 6) {
      std::string word;
      // Read origin state
      if (flujo >> word) {
        auto it = this->states_.find(State(word));
        if (it == this->states_.end()) {
          std::string error_message = "State " + word + " of transition rule not in state set";
          throw std::runtime_error(error_message);
        }
        State new_state = *it;
        
        // Read consumed symbol
        if (flujo >> word) {
          char consumed_symbol = word[0];
          auto it_consumed = this->alphabet_.IsSymbolPresent(Symbol(consumed_symbol));
          if (!it_consumed) {
            std::string error_message = "Consumed symbol " + std::string(1, consumed_symbol) + " not in alphabet";
            throw std::runtime_error(error_message);
          }
          
          // Read consumed stack symbol
          if (flujo >> word) {
            char consumed_stack_symbol = word[0];
            // std::cout << "Consumed stack symbol: " << consumed_stack_symbol << std::endl;
            auto it_consumed_stack = this->stack_alphabet_.IsSymbolPresent(Symbol(consumed_stack_symbol));
            if (!it_consumed_stack) {
              std::string error_message = "Consumed stack symbol " + std::string(1, consumed_stack_symbol) + " not in stack alphabet";
              throw std::runtime_error(error_message);
            }
            // Read destination state
            if (flujo >> word) {
              std::string destine_state = word;
              if (this->states_.find(State(destine_state)) == this->states_.end()) {
                std::string error_message = "Destination state " + destine_state + " not in state set";
                throw std::runtime_error(error_message);
              }
              
              // Read stack write
              if (flujo >> word) {
                std::string stack_write = word;
                for (char c : stack_write) {
                  if (!this->stack_alphabet_.IsSymbolPresent(Symbol(c))) {
                    std::string error_message = "Stack symbol " + std::string(1, c) + " not in stack alphabet";
                    throw std::runtime_error(error_message);
                  }
                }
                new_state.AddTransition(consumed_symbol, consumed_stack_symbol, destine_state, stack_write);
                this->states_.erase(it);
                this->states_.insert(new_state);
              } else throw std::runtime_error("Failed to read transition rule stack write");
            } else throw std::runtime_error("Failed to read transition rule destination state");
          } else throw std::runtime_error("Failed to read transition rule consumed stack symbol");
        } else throw std::runtime_error("Failed to read transition rule consumed symbol");
      } else throw std::runtime_error("Failed to read transition rule initial state");
    }
  }
}

/**
 * @brief Print the details of the finite automaton.
 */
void FinalAutomaton::Print() const {
  std::cout << "Conjunto de estados: ";
  for (const auto& state : this->states_) {
    std::cout << state.GetID() << " ";
  }
  std::cout << "\nConjunto de símbolos: ";
  for (const auto& symbol : this->alphabet_.GetSymbols()) {
    if (symbol.GetValue() != '.') std::cout << symbol.GetValue() << " ";
  }
  std::cout << "\nConjunto de símbolos de pila: ";
  for (const auto& symbol : this->stack_alphabet_.GetSymbols()) {
    if (symbol.GetValue() != '.') std::cout << symbol.GetValue() << " ";
  }
  std::cout << "\nEstado inicial: " << this->initial_state_.GetID();
  std::cout << "\nSímbolo inicial de pila: " << this->stack_.Top();
  std::cout << "\nEstado final: " << this->final_state_.GetID() << std::endl;
  for (const auto& state : this->states_) {
    std::cout << "Estado: " << state.GetID() << std::endl;
    state.PrintIterations();
  }
}

/**
 * @brief Evaluate the finite automaton with the given input file.
 * @param input_file_name The name of the input file to read.
 */
void FinalAutomaton::Evaluate(const std::string& input_string, const bool& debug_mode) {
  TriedMap tried_map;
  State initial_state;
  for (const auto& state : this->states_) {
    if (state.GetID() == this->initial_state_.GetID()) {
      initial_state = state;
    }
  }
  if (EvaluateString(input_string, initial_state, 0u, tried_map, 1, debug_mode)) {
    if (!debug_mode) std::cout << std::left << std::setw(15) << input_string << " → ✅  ACEPTADA\n";
  } else if (!debug_mode) std::cout << std::left << std::setw(15) << input_string << " → ❌  RECHAZADA\n";
}

bool FinalAutomaton::EvaluateString(
    const std::string& input_string,
    const State& current_state,
    std::size_t pos,
    TriedMap& tried,
    const int& depth,
    const bool& debug_mode
) {
  const std::size_t n = input_string.size();

  // Construimos configuración actual
  std::string cadena_restante = input_string.substr(pos);
  std::string pila_serializada = SerializeStackCopy(stack_);
  std::string indent(depth * 2, ' ');

  // DEBUG: Estado actual
  if (debug_mode) {
    std::cout << indent << "\033[1;35m[DEBUG]\033[0m " "\033[36mEstado\033[0m = " << current_state.GetID()
              << " | \033[36mCadena\033[0m = " << (cadena_restante.empty() ? "ε" : "\"" + cadena_restante + "\"")
              << " | \033[36mPila\033[0m = " << (pila_serializada.empty() ? "ε" : pila_serializada);
  }

  // --- Mostrar transiciones posibles ---
  if (debug_mode) {
    const auto& transitions = current_state.GetTransitions();
    std::vector<std::string> posibles;

    for (const Transition& t : transitions) {
      char t_input = t.GetSymbol();
      char t_stack = t.GetStackSymbol();

      bool inputOk = (t_input == '.') || (pos < n && t_input == input_string[pos]);
      bool stackOk = (t_stack == '.') || (!stack_.IsEmpty() && stack_.Top() == t_stack);

      if (inputOk && stackOk) {
        std::string trans_str = "(" +
          (t_input == '.' ? "ε" : std::string(1, t_input)) + ", " +
          (t_stack == '.' ? "ε" : std::string(1, t_stack)) + " → " +
          t.GetNextState() + ", " +
          (t.GetStackWrite().empty() || t.GetStackWrite() == "." ? "ε" : t.GetStackWrite()) + ")";
        posibles.push_back(trans_str);
      }
    }

    if (!posibles.empty()) {
      std::cout << " | \033[36mTransiciones posibles\033[0m: ";
      for (size_t i = 0; i < posibles.size(); ++i) {
        std::cout << "\033[35m" << posibles[i] << "\033[0m";
        if (i + 1 < posibles.size()) std::cout << ", \033[33m";
      }
    } else {
      std::cout << " | \033[31;4mSin transiciones válidas\033[0m";
    }
    std::cout << std::endl;
  }

  // 1) Condición de aceptación
  if (pos == n && current_state.GetID() == final_state_.GetID()) {
    if (debug_mode) {
      std::cout << indent << "✅ ACEPTADA: cadena vacía y estado final alcanzado ("
                << current_state.GetID() << ")\n";
    }
    return true;
  }

  // Serializamos la configuración actual
  ConfigKey cfg = std::make_tuple(current_state.GetID(), pos, pila_serializada);

  // 2) Recorremos transiciones salientes
  const auto& transitions = current_state.GetTransitions();
  for (const Transition& trans : transitions) {
    TransitionKey tkey = trans.GetTransition();

    // Evitar repetir la misma transición desde esta configuración
    auto itCfg = tried.find(cfg);
    if (itCfg != tried.end() && itCfg->second.find(tkey) != itCfg->second.end()) {
      continue;
    }

    // --- Coincidencia con la entrada ---
    char t_input = trans.GetSymbol();
    bool inputMatches = (t_input == '.') || (pos < n && t_input == input_string[pos]);
    if (!inputMatches) continue;

    // --- Coincidencia con la pila ---
    char t_stack = trans.GetStackSymbol();
    bool stackMatches = (t_stack == '.') || (!stack_.IsEmpty() && stack_.Top() == t_stack);
    if (!stackMatches) continue;

    // --- Aplicar transición (backup previo) ---
    Stack<char> stack_backup = stack_;
    bool consumesInput = (t_input != '.');

    // Pop si corresponde
    if (t_stack != '.') {
      if (stack_.IsEmpty()) { stack_ = stack_backup; continue; }
      stack_.Pop();
    }

    // Escritura en pila ('.' = no escribir nada)
    std::string write = trans.GetStackWrite();
    if (!(write.empty() || write == ".")) {
      for (auto it = write.rbegin(); it != write.rend(); ++it) {
        stack_.Push(*it);
      }
    }

    // Marcar transición como probada
    tried[cfg].insert(tkey);

    // DEBUG: Transición usada
    if (debug_mode) {
      std::cout << indent << " ├── \033[34mUsa transición\033[0m: \033[35m("
                << current_state.GetID() << ", "
                << (t_input == '.' ? "ε" : std::string(1, t_input)) << ", "
                << (t_stack == '.' ? "ε" : std::string(1, t_stack))
                << ") → (" << trans.GetNextState() << ", "
                << (write.empty() || write == "." ? "ε" : write)
                << ")\033[0m" << std::endl;
    }

    // Estado y posición siguientes
    State nextState = GetStateByID(trans.GetNextState());
    std::size_t nextPos = pos + (consumesInput ? 1u : 0u);

    // Recursión
    if (EvaluateString(input_string, nextState, nextPos, tried, depth + 1, debug_mode)) {
      return true;
    }

    // --- BACKTRACKING ---
    stack_ = stack_backup;
    if (debug_mode)
      std::cout << indent << " 🔙 Backtracking desde estado "
                << nextState.GetID() << " a " << current_state.GetID() << std::endl;
  }

  // Si ninguna transición llevó a aceptación
  if (debug_mode) {
    std::cout << indent << "❌ Dead end en estado " << current_state.GetID()
              << " con cadena=\"" << (cadena_restante.empty() ? "." : cadena_restante)
              << "\" y pila=" << (pila_serializada.empty() ? "." : pila_serializada)
              << std::endl;
  }

  return false;
}

