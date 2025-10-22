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
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "../include/multi-tapeTM.hpp"

MultiTapeTuringMachine::MultiTapeTuringMachine(const std::string& config_file_name) {
  std::ifstream config_file(config_file_name);
  if (!config_file) {
    throw std::runtime_error("Could not open config file");
  }

  // Leer la configuración del archivo
  std::string line;
  int counter = 0;
  while (std::getline(config_file, line)) {
    if (line[0] == '#') continue;
    std::stringstream flujo(line);

    // States in the TM
    if (counter == 0) {
      std::string state;
      while (flujo >> state) {
        MultiTapeState new_state(state);
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
        this->input_symbols_alphabet_.AddSymbol(new_symbol);
      }
      counter++;
      continue;
    }

    // Tape symbols in the TM
    if (counter == 2) {
      std::string tape_symbol;
      while (flujo >> tape_symbol) {
        if (tape_symbol.size() > 1) {
          throw std::runtime_error("\033[1;31mStack symbol too long\033[0m");
        }
        Symbol new_tape_symbol(tape_symbol[0]);
        this->tape_symbols_alphabet_.AddSymbol(new_tape_symbol);
      }
      counter++;
      continue;
    }

    // Initial state of the TM
    if (counter == 3) {
      std::string initial_state_id;
      if (flujo >> initial_state_id) {
        if (this->states_.find(MultiTapeState(initial_state_id)) == this->states_.end()) {
          throw std::runtime_error("\033[1;31mInitial state not in state set\033[0m");
        }
        this->initial_state_ = MultiTapeState(initial_state_id);
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
        if (this->states_.find(MultiTapeState(final_state_id)) == this->states_.end()) {
          throw std::runtime_error("\033[1;31mFinal state not in state set\033[0m");
        }
        this->final_states_.emplace(MultiTapeState(final_state_id));
      }
      counter++;
      continue;
    }

    // Number of tapes
    if (counter == 6) {
      int num_tapes;
      if (flujo >> num_tapes) {
        if (num_tapes <= 0) {
          throw std::runtime_error("\033[1;31mInvalid number of tapes\033[0m");
        }
        this->num_tapes_ = num_tapes;
        this->tapes_.resize(num_tapes_, Tape(this->blank_symbol_));
      } else throw std::runtime_error("\033[1;31mFailed to read number of tapes\033[0m");
      counter++;
      continue;
    }

    // Transitions of the TM
    if (counter == 7) {
      std::string word;

      // Read origin state
      if (flujo >> word) {
        auto it = this->states_.find(MultiTapeState(word));
        if (it == this->states_.end()) {
          std::string error_message = "\033[1;31mState " + word + " of transition rule not in state set\033[0m";
          throw std::runtime_error(error_message);
        }
        MultiTapeState new_state = *it;

        // Read symbols
        std::vector<Symbol> read_symbols;
        for (int i = 0; i < this->num_tapes_; ++i) {
          std::string symbol;
          if (flujo >> symbol) {
            if (symbol.size() > 1) {
              throw std::runtime_error("\033[1;31mSymbol too long\033[0m");
            }
            char symbol_char = symbol[0];
            auto it_read = this->input_symbols_alphabet_.IsSymbolPresent(symbol_char);
            if (!it_read && !this->tape_symbols_alphabet_.IsSymbolPresent(symbol_char)) {
              std::string error_message = "\033[1;31mSymbol " + word + " of transition rule not in symbols alphabet\033[0m";
              throw std::runtime_error(error_message);
            }
            read_symbols.push_back(Symbol(symbol_char));
          } else {
            throw std::runtime_error("\033[1;31mFailed to read symbol\033[0m");
          }
        }

        // Read destination state
        std::string destination_state;      
        if (flujo >> word) {
          auto it = this->states_.find(MultiTapeState(word));
          if (it == this->states_.end()) {
            std::string error_message = "\033[1;31mState " + word + " of transition rule not in state set\033[0m";
            throw std::runtime_error(error_message);
          }
          destination_state = word;
        } else {
          throw std::runtime_error("\033[1;31mFailed to read destination state\033[0m");
        }

        // Write tape symbols and movements
        std::vector<Symbol> write_symbols;
        std::vector<Movement> movements;
        for (int i = 0; i < this->num_tapes_; ++i) {
          std::string symbol;
          std::string word;
          if (flujo >> symbol >> word) {
            if (symbol.size() > 1) {
              throw std::runtime_error("\033[1;31mSymbol too long\033[0m");
            }
            char symbol_char = symbol[0];
            auto it_write = this->tape_symbols_alphabet_.IsSymbolPresent(symbol_char);
            if (!it_write) {
              std::string error_message = "\033[1;31mSymbol " + word + " of transition rule not in symbols alphabet\033[0m";
              throw std::runtime_error(error_message);
            }
            write_symbols.push_back(Symbol(symbol_char));
            if (word == "L") {
              movements.push_back(Movement::LEFT);
            } else if (word == "R") {
              movements.push_back(Movement::RIGHT);
            } else if (word == "S") {
              movements.push_back(Movement::STAY);
            } else {
              throw std::runtime_error("\033[1;31mInvalid movement direction\033[0m");
            }
          } else {
            throw std::runtime_error("\033[1;31mFailed to read symbol\033[0m");
          }
        }
        std::vector<Transition> transitions;
        for (int i = 0; i < this->num_tapes_; ++i) {
          TransitionParams params;
          params.read_symbol = read_symbols[i];
          params.next_state = destination_state;
          params.write_symbol = write_symbols[i];
          params.movement = movements[i];
          Transition transition(params);
          transitions.push_back(transition);
        }
        new_state.AddTransition(transitions);
        this->states_.erase(it);
        this->states_.insert(new_state);
        if (this->final_states_.find(*it) != this->final_states_.end()) {
          this->final_states_.erase(*it);
          this->final_states_.emplace(new_state);
        }
        if (this->initial_state_ == *it) {
          this->initial_state_ = new_state;
        }
      } else throw std::runtime_error("\033[1;31mFailed to update transition rule\033[0m");
    }
  }
}

bool MultiTapeTuringMachine::Simulate(const std::string& input) {
  for (auto& tape : this->tapes_) {
    tape.ClearTape();
  }
  this->tapes_[0].AddWord(input);

  MultiTapeState current_state = this->initial_state_;
  int counter = 0;
  std::vector<std::list<Symbol>::const_iterator> iterators;
  for (const auto& tape : this->tapes_) {
    iterators.push_back(tape.GetTapeContents().begin());
  }
  std::vector<std::list<Symbol>::const_iterator> ends_iterators;
  for (const auto& tape : this->tapes_) {
    ends_iterators.push_back(tape.GetTapeContents().end());
  }

  // Main simulation loop
  while (iterators[0] != ends_iterators[0]) {
    std::vector<Symbol> current_symbols;
    for (size_t i = 0; i < iterators.size(); ++i) {
      current_symbols.push_back(*iterators[i]);
    }
    if (counter == 0) {
      counter++;
      for (size_t i = 0; i < iterators.size(); ++i) {
        ++iterators[i];
      }
      continue;
    }

    current_state.PrintTransitions();
    for (const auto& tape : this->tapes_) {
      tape.PrintTape();
    }

    // Get the transition for the current state and symbols
    auto maybe_params = current_state.GetTransition(current_symbols);
    if (maybe_params) {
      const std::vector<Transition> params = *maybe_params;
      auto it_state = this->states_.find(MultiTapeState(params[0].GetTransition().next_state));
      current_state = *it_state;
      for (size_t i = 0; i < tapes_.size(); ++i) {
        tapes_[i].WriteSymbol(params[i].GetTransition().write_symbol);
        tapes_[i].MoveHead(params[i].GetTransition().movement);
        if (params[i].GetMovement() == Movement::LEFT) iterators[i]--;
        else if (params[i].GetMovement() == Movement::RIGHT) iterators[i]++;
      }
    } else {
      for (const auto& state : this->final_states_) {
        if (state == current_state) {
          std::cout << std::left << std::setw(15) << input << " → ✅  ACEPTADA\n";
          // for (auto& tape : this->tapes_) {
          //   tape.ResetHead();
          //   tape.FormatTape();
          //   tape.PrintTape();
          // }
          return true;
        }
      }
      break;
    }
    for (size_t i = 0; i < ends_iterators.size(); ++i) {
      ends_iterators[i] = tapes_[i].GetTapeContents().end();
    }
  }
  std::cout << std::left << std::setw(15) << input << " → ❌  RECHAZADA\n";
  // for (auto& tape : this->tapes_) {
  //   tape.ResetHead();
  //   tape.FormatTape();
  //   tape.PrintTape();
  // }
  return false;
}

void MultiTapeTuringMachine::CheckInputs(const std::string& input_file_name) {
  std::ifstream input_file(input_file_name);
  if (!input_file.is_open()) {
    throw std::runtime_error("\033[1;31mFailed to open input file\033[0m");
  }

  std::string word;
  while (input_file >> word) {
    this->Simulate(word);
  }
}