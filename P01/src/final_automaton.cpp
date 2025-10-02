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
                new_state.AddTransition(consumed_symbol, consumed_symbol, destine_state, stack_write);
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

void FinalAutomaton::Print() const {
  std::cout << "Conjunto de estados: ";
  for (const auto& state : this->states_) {
    std::cout << state.GetID() << " ";
  }
  std::cout << "\nConjunto de símbolos: ";
  for (const auto& symbol : this->alphabet_.GetSymbols()) {
    std::cout << symbol.GetValue() << " ";
  }
  std::cout << "\nConjunto de símbolos de pila: ";
  for (const auto& symbol : this->stack_alphabet_.GetSymbols()) {
    std::cout << symbol.GetValue() << " ";
  }
  std::cout << "\nEstado inicial: " << this->initial_state_.GetID();
  std::cout << "\nSímbolo inicial de pila: " << this->stack_.Top();
  std::cout << "\nEstado final: " << this->final_state_.GetID() << std::endl;
  for (const auto& state : this->states_) {
    std::cout << "Estado: " << state.GetID() << std::endl;
    state.PrintIterations();
  }
}