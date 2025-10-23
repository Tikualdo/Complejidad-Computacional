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
#include "../include/multi-tape_state.hpp"

/**
 * @brief Checks if the state has a specific transition.
 * @param read_symbols The symbols to read.
 * @param write_symbols The symbols to write.
 * @return True if the transition exists, false otherwise.
 */
bool MultiTapeState::HasTransition(std::vector<Symbol> read_symbols, std::vector<Symbol> write_symbols) const {
  for (const auto& transition : transitions_) {
    if (transition.size() == read_symbols.size() && transition.size() == write_symbols.size()) {
      bool match = true;
      for (size_t i = 0; i < transition.size(); ++i) {
        if (transition[i].GetSymbol().GetValue() != read_symbols[i].GetValue() || transition[i].GetWriteSymbol().GetValue() != write_symbols[i].GetValue()) {
          match = false;
          break;
        }
      }
      if (match) {
        return true;
      }
    }
  }
  return false;
}

/**
 * @brief Gets the transition for a specific set of read symbols.
 * @param read_symbols The symbols to read.
 * @return An optional vector of transitions if found, otherwise nullopt.
 */
std::optional<std::vector<Transition>> MultiTapeState::GetTransition(const std::vector<Symbol>& read_symbols) const {
  for (const auto& transition : transitions_) {
    if (transition.size() == read_symbols.size()) {
      bool match = true;
      for (size_t i = 0; i < transition.size(); ++i) {
        if (transition[i].GetSymbol().GetValue() != read_symbols[i].GetValue()) {
          match = false;
          break;
        }
      }
      if (match) {
        return transition;
      }
    }
  }
  return std::nullopt;
}

/**
 * @brief Prints the transitions of the state.
 */
void MultiTapeState::PrintTransitions() const {
  for (const auto& transition : transitions_) {
    std::cout << this->GetID() << " ";
    for (const auto& t : transition) {
      std::cout << t.GetSymbol().GetValue() << " " <<  t.GetNextState() << " " << t.GetWriteSymbol().GetValue() << " ";
      if (Movement::LEFT == t.GetMovement()) std::cout << "L ";
      else if (Movement::RIGHT == t.GetMovement()) std::cout << "R ";
      else std::cout << "S ";
    }
    std::cout << std::endl;
  }
}