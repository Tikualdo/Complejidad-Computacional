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
#include "../include/single-tape_state.hpp"

/**
 * @brief Adds a transition to the state.
 * @param transition The transition to add.
 */
void SingleTapeState::AddTransition(const TransitionParams& transition) {
  Transition new_transition(transition);
  transitions_.emplace(new_transition);
}

/**
 * @brief Checks if the state has a specific transition.
 * @param read_symbol The symbol to read.
 * @param write_symbol The symbol to write.
 * @return True if the transition exists, false otherwise.
 */
bool SingleTapeState::HasTransition(const Symbol& read_symbol, const Symbol& write_symbol) const {
  for (const auto& transition : transitions_) {
    if (transition.GetSymbol() == read_symbol && transition.GetWriteSymbol() == write_symbol) {
      return true;
    }
  }
  return false;
}

std::optional<TransitionParams> SingleTapeState::GetTransition(const Symbol& symbol) const {
  for (const auto& transition : transitions_) {
    if (transition.GetSymbol() == symbol) {
      return transition.GetTransition();
    }
  }
  return std::nullopt;
}

/**
 * @brief Prints all transitions of the state.
 */
void SingleTapeState::PrintTransitions() const {
  for (const auto& transition : transitions_) {
    std::cout << this->GetID() << " " << transition.GetSymbol().GetValue()
              << " " << transition.GetNextState() << " "
              << transition.GetWriteSymbol().GetValue() << " "
              << ToString(transition.GetMovement()) << std::endl;
  }
}
