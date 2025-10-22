/**
  * Universidad de La Laguna 
  * Escuela Superior de Ingeniería y Tecnología 
  * Grado en Ingeniería Informática 
  * Complejidad Computacional
  * 
  * @author Paulo Padilla Domingues 
  * @date Oct 14 2025 
  * @brief
  * 
  * Archivo 
  * Historial de revisiones
  *     // 
*/
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "../include/single-tapeTM.hpp"

/**
 * @brief Constructs a Turing machine from a configuration file.
 * @param config_file_name The name of the configuration file.
 */
SingleTapeTuringMachine::SingleTapeTuringMachine(const std::string& config_file_name) {
  std::ifstream config_file(config_file_name);
  if (!config_file) {
    std::cerr << "Error: No se pudo abrir el archivo de configuración.\n";
    return;
  }

  // Leer la configuración del archivo
  std::string line;
  int counter = 0;
  while (std::getline(config_file, line)) {
    if (line[0] == '#') continue;
    std::stringstream flujo(line);

    // States in the TM
    if (counter == 0) {
      std::string state_id;
      while (flujo >> state_id) {
        SingleTapeState new_state(state_id);
        this->states_.emplace(new_state);
      }
      counter++;
      continue;
    }

    // Symbols in the TM
    if (counter == 1) {
      std::string symbol;
      while (flujo >> symbol) {
        if (symbol.size() > 1) {
          throw std::runtime_error("\033[1;31mSymbol too long\033[0m");
        }
        Symbol new_symbol(symbol[0]);
        this->input_symbols_alphabet_.AddSymbol(new_symbol.GetValue());
      }
      counter++;
      continue;
    }

    // Tape symbols in the TM
    if (counter == 2) {
      std::string symbol;
      while (flujo >> symbol) {
        if (symbol.size() > 1) {
          throw std::runtime_error("\033[1;31mStack symbol too long\033[0m");
        }
        Symbol new_symbol(symbol[0]);
        this->tape_symbols_alphabet_.AddSymbol(new_symbol.GetValue());
      }
      counter++;
      continue;
    }

    // Initial state of the TM
    if (counter == 3) {
      std::string initial_state_id;
      if (flujo >> initial_state_id) {
        if (this->states_.find(SingleTapeState(initial_state_id)) == this->states_.end()) {
          throw std::runtime_error("\033[1;31mInitial state not in state set\033[0m");
        }
        this->initial_state_ = SingleTapeState(initial_state_id);
      } else throw std::runtime_error("\033[1;31mFailed to read initial state\033[0m");
      counter++;
      continue;
    }

    // Blank symbol of the TM
    if (counter == 4) {
      std::string blank_symbol;
      if (flujo >> blank_symbol) {
        if (blank_symbol.size() > 1) {
          throw std::runtime_error("\033[1;31mBlank symbol too long\033[0m");
        }
        this->blank_symbol_ = Symbol(blank_symbol[0]);
      } else throw std::runtime_error("\033[1;31mFailed to read blank symbol\033[0m");
      if (this->input_symbols_alphabet_.GetSymbols().find(this->blank_symbol_) != this->input_symbols_alphabet_.GetSymbols().end()) {
        throw std::runtime_error("\033[1;31mBlank symbol must not be part of the input symbols alphabet\033[0m");
      }
      Tape tape(this->blank_symbol_);
      this->tape_ = tape;
      counter++;
      continue;
    }

    // Final states of the TM
    if (counter == 5) {
      std::string final_state_id;
      while (flujo >> final_state_id) {
        if (final_state_id.size() == 0) {
          throw std::runtime_error("\033[1;31mFailed to read final state\033[0m");
        }
        if (this->states_.find(SingleTapeState(final_state_id)) == this->states_.end()) {
          throw std::runtime_error("\033[1;31mFinal state not in state set\033[0m");
        }
        this->final_states_.emplace(SingleTapeState(final_state_id));
      }
      counter++;
      continue;
    }

    // Transitions of the TM
    if (counter == 6) {
      std::string word;

      // Read origin state
      if (flujo >> word) {
        auto it = this->states_.find(SingleTapeState(word));
        if (it == this->states_.end()) {
          std::string error_message = "\033[1;31mState " + word + " of transition rule not in state set\033[0m";
          throw std::runtime_error(error_message);
        }
        SingleTapeState new_state = *it;

        // Read symbol
        if (flujo >> word) {
          char symbol = word[0];
          Symbol read_symbol(symbol);
          auto it_read = this->input_symbols_alphabet_.IsSymbolPresent(read_symbol);
          if (!it_read && !this->tape_symbols_alphabet_.IsSymbolPresent(read_symbol)) {
            std::string error_message = "\033[1;31mSymbol " + word + " of transition rule not in symbols alphabet\033[0m";
            throw std::runtime_error(error_message);
          }
          
          // Read destination state
          if (flujo >> word) {
            std::string destinate_state_id = word;
            if (this->states_.find(SingleTapeState(destinate_state_id)) == this->states_.end()) {
              std::string error_message = "\033[1;31mState " + destinate_state_id + " of transition rule not in state set\033[0m";
              throw std::runtime_error(error_message);
            }
            
            // Write tape symbol
            if (flujo >> word) {
              symbol = word[0];
              Symbol write_symbol(symbol);
              auto it_write = this->tape_symbols_alphabet_.IsSymbolPresent(write_symbol);
              if (!it_write && !this->input_symbols_alphabet_.IsSymbolPresent(write_symbol)) {
                std::string error_message = "\033[1;31mSymbol " + word + " of transition rule not in symbols alphabet\033[0m";
                throw std::runtime_error(error_message);
              }

              // Movement direction
              if (flujo >> word) {
                Movement move;
                if (word == "L") {
                   move = Movement::LEFT;
                } else if (word == "R") {
                  move = Movement::RIGHT;
                } else if (word == "S") {
                  move = Movement::STAY;
                } else {
                  std::string error_message = "\033[1;31mInvalid movement direction " + word + "\033[0m";
                  throw std::runtime_error(error_message);
                }
                TransitionParams params;
                params.read_symbol = read_symbol;
                params.next_state = destinate_state_id;
                params.write_symbol = write_symbol;
                params.movement = move;
                new_state.AddTransition(params);
                this->states_.erase(it);
                this->states_.emplace(new_state);
                if (this->final_states_.find(*it) != this->final_states_.end()) {
                  this->final_states_.erase(*it);
                  this->final_states_.emplace(new_state);
                }
                if (this->initial_state_ == *it) {
                  this->initial_state_ = new_state;
                }
              } else throw std::runtime_error("\033[1;31mFailed to read movement direction\033[0m");
            } else throw std::runtime_error("\033[1;31mFailed to read write tape symbol\033[0m");
          } else throw std::runtime_error("\033[1;31mFailed to read destination state\033[0m");
        } else throw std::runtime_error("\033[1;31mFailed to read read symbol\033[0m");
      } else throw std::runtime_error("\033[1;31mFailed to read origin state\033[0m");
    }
  }
}

/**
 * @brief Simulates the Turing machine on an input tape.
 * @param word The input word to process.
 * @return True if the simulation was successful, false otherwise.
 */
bool SingleTapeTuringMachine::Simulate(const std::string& word) {
  this->tape_.AddWord(word);

  SingleTapeState current_state = this->initial_state_;
  int counter = 0;
  auto it = this->tape_.GetTapeContents().begin();
  auto end = this->tape_.GetTapeContents().end();
  while (it != end) {
    const Symbol& symbol = *it;
    if (counter == 0) {
      counter++;
      it++;
      continue;
    }
    // current_state.PrintTransitions();
    // this->tape_.PrintTape();

    // std::cout << symbol.GetValue() << std::endl;

    // Get the transition for the current state and symbol
    auto maybe_params = current_state.GetTransition(symbol);
    if (maybe_params) {
      const TransitionParams params = *maybe_params;
      auto it_state = this->states_.find(SingleTapeState(params.next_state));
      current_state = *it_state;
      this->tape_.WriteSymbol(params.write_symbol);
      // std::cout << std::left << std::setw(15) << word << " → " << symbol.GetValue() << " → " << params.write_symbol.GetValue() << " → " << ToString(params.movement) << std::endl;
      this->tape_.MoveHead(params.movement);
      if (params.movement == Movement::RIGHT) ++it;
      if (params.movement == Movement::LEFT) --it;
    } else {
      for (const auto& state : this->final_states_) {
        if (state == current_state) {
          std::cout << std::left << std::setw(15) << word << " → ✅  ACEPTADA\n";
          return true;
        }
      }
      break;
    }
    end = this->tape_.GetTapeContents().end();
  }
  std::cout << std::left << std::setw(15) << word << " → ❌  RECHAZADA\n";
  return false;
}

void SingleTapeTuringMachine::CheckInputs(const std::string& input_file_name) {
  std::ifstream input_file(input_file_name);
  if (!input_file) {
    std::cerr << "Error: No se pudo abrir el archivo de entrada." << std::endl;
    return;
  }

  std::string word;
  while (input_file >> word) {
    this->Simulate(word);
  }
}