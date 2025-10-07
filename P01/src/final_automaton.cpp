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

static inline bool IsEpsilonChar(char c) {
  return c == '.';
}

static std::string SerializeStackCopy(Stack<char> stackCopy) {
  std::string s;
  // Concatenamos caracteres desde la cima hacia abajo -> representación consistente
  while (!stackCopy.IsEmpty()) {
    s.push_back(stackCopy.Pop()); // Pop devuelve el top
  }
  return s;
}

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
void FinalAutomaton::Evaluate(const std::string& input_file_name) {
  std::ifstream input_file(input_file_name);
  if (!input_file) {
    std::cerr << "Error opening input file: " << input_file_name << std::endl;
    return;
  }
  std::string line;
  std::vector<std::string> input_strings;
  while (std::getline(input_file, line)) {
    std::stringstream flujo(line);
    std::string word;
    if (flujo >> word) {
      input_strings.push_back(word);
    } else throw std::runtime_error("Failed to read word from input line");
  }
  TriedMap tried_map;
  State initial_state;
  for (const auto& state : this->states_) {
    if (state.GetID() == this->initial_state_.GetID()) {
      initial_state = state;
    }
  }
  for (const auto& input_string : input_strings) {
    if (EvaluateString(input_string, initial_state, 0u, tried_map, 1)) {
      std::cout << "Cadena aceptada: " << input_string << std::endl;
    } else {
      std::cout << "Cadena no aceptada: " << input_string << std::endl;
    }
  }
}

// bool FinalAutomaton::EvaluateString(
//     const std::string& input_string,
//     const State& current_state,
//     std::set<std::pair<Transition,
//     bool>>& visited_transitions
//   ) {
  
//   // Cadena vacía
//   if (input_string.empty()) {
//     if (current_state.GetID() == this->final_state_.GetID()) return true;
//     bool has_transitions = false;
//     std::string name_next_state;
//     for (auto& visited_transition : visited_transitions) {
//       if (visited_transition.first.EvaluateTransition('.', this->stack_.Top()) && !visited_transition.second) {
//         has_transitions = true;
//         name_next_state = visited_transition.first.GetNextState();
//         std::pair<Transition, bool> updated_transition = {visited_transition.first, true};
//         visited_transitions.erase(visited_transition);
//         visited_transitions.insert(updated_transition);
//         break;
//       }
//     }
//     if (has_transitions) {
//       if (this->stack_.Top() != '.') this->stack_.Pop();
//       State next_state;
//       for (const auto& state : this->states_) {
//         if (state.GetID() == name_next_state) {
//           next_state = state;
//         }
//       }
//       if (next_state.GetID() == "<>") throw std::runtime_error("Next state is invalid");
//       std::set<std::pair<Transition, bool>> next_visited_transitions;
//       for (auto& transition : next_state.GetTransitions()) {
//         next_visited_transitions.emplace(transition, false);
//       }
//       if (EvaluateString(input_string, next_state, next_visited_transitions)) {
//         return true;
//       } else return false;
//     } else return false;
//   }

//   // Cadena no vacía
//   if (!input_string.empty()) {
//     char current_symbol = input_string[0];
//     std::string remaining_string = input_string.substr(1);
//     for (const auto& transition : visited_transitions) {
//       if (transition.first.EvaluateTransition(current_symbol, this->stack_.Top()) && !transition.second) {
//         State next_state = transition.first.GetNextState();
//         std::pair<Transition, bool> updated_transition = {transition.first, true};
//         visited_transitions.erase(transition);
//         visited_transitions.insert(updated_transition);
//         std::set<std::pair<Transition, bool>> next_visited_transitions;
//         for (auto& transition : next_state.GetTransitions()) {
//           next_visited_transitions.emplace(transition, false);
//         }
//         if (EvaluateString(remaining_string, next_state, next_visited_transitions)) {
//           return true;
//         } else return false;
//       } else if (transition.first.EvaluateTransition('.', this->stack_.Top()) && !transition.second) {
//         State next_state = transition.first.GetNextState();
//         std::set<std::pair<Transition, bool>> next_visited_transitions;
//         for (auto& transition : next_state.GetTransitions()) {
//           next_visited_transitions.emplace(transition, false);
//         }
//         if (EvaluateString(input_string, next_state, next_visited_transitions)) {
//           return true;
//         } else return false;
//       }
//     }
//   }
//   return false;
// }

bool FinalAutomaton::EvaluateString(
    const std::string& input_string,
    const State& current_state,
    std::size_t pos,
    TriedMap& tried,
    int depth  // para depuración visual
) {
  const std::size_t n = input_string.size();

  // Construimos configuración actual
  std::string cadena_restante = input_string.substr(pos);
  std::string pila_serializada = SerializeStackCopy(stack_);
  std::string indent(depth * 2, ' ');  // para sangría visual

  // DEBUG: Estado actual
  std::cout << indent << "[CFG] Estado=" << current_state.GetID()
            << " | Cadena=\"" << (cadena_restante.empty() ? "." : cadena_restante)
            << "\" | Pila=" << (pila_serializada.empty() ? "." : pila_serializada)
            << std::endl;

  // 1) Condición de aceptación: por estado final (no por pila vacía)
  if (pos == n && current_state.GetID() == final_state_.GetID()) {
    std::cout << indent << "✔ ACEPTADA: cadena vacía y estado final alcanzado ("
              << current_state.GetID() << ")\n";
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
    bool inputMatches = false;
    if (t_input == '.') {  // épsilon de entrada
      inputMatches = true;
    } else if (pos < n && t_input == input_string[pos]) {
      inputMatches = true;
    }
    if (!inputMatches) continue;

    // --- Coincidencia con la pila ---
    char t_stack = trans.GetStackSymbol();
    bool stackMatches = false;
    if (t_stack == '.') {  // épsilon en pila (no hace pop)
      stackMatches = true;
    } else if (!stack_.IsEmpty() && stack_.Top() == t_stack) {
      stackMatches = true;
    }
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
      // push inverso: si "AB" → top será 'A'
      for (auto it = write.rbegin(); it != write.rend(); ++it) {
        stack_.Push(*it);
      }
    }

    // Marcar transición como probada desde esta configuración
    tried[cfg].insert(tkey);

    // DEBUG: Transición usada
    std::cout << indent << " ├── Usa transición: ("
              << current_state.GetID() << ", "
              << (t_input == '.' ? "ε" : std::string(1, t_input)) << ", "
              << (t_stack == '.' ? "ε" : std::string(1, t_stack))
              << ") → (" << trans.GetNextState() << ", "
              << (write.empty() ? "ε" : write) << ")"
              << std::endl;

    // Estado y posición siguientes
    State nextState = GetStateByID(trans.GetNextState());
    std::size_t nextPos = pos + (consumesInput ? 1u : 0u);

    // Recursión
    if (EvaluateString(input_string, nextState, nextPos, tried, depth + 1)) {
      return true;
    }

    // --- BACKTRACKING ---
    stack_ = stack_backup;
    std::cout << indent << " ↩ Backtracking desde estado "
              << nextState.GetID() << " a " << current_state.GetID() << std::endl;
  }

  // Ninguna transición desde aquí lleva a aceptación
  std::cout << indent << "✘ Dead end en estado " << current_state.GetID()
            << " con cadena=\"" << (cadena_restante.empty() ? "." : cadena_restante)
            << "\" y pila=" << (pila_serializada.empty() ? "." : pila_serializada)
            << std::endl;

  return false;
}
