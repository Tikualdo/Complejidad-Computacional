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
#include "../include/state.hpp"

/**
 * @brief Adds a transition to the state.
 * @param transition The transition to add.
 */
void State::AddTransition(const TransitionParams& transition) {
  transitions_.emplace(new Transition(transition));
}

/**
 * @brief Checks if the state has a specific transition.
 * @param read_symbol The symbol to read.
 * @param write_symbol The symbol to write.
 * @return True if the transition exists, false otherwise.
 */
bool State::HasTransition(const Symbol& read_symbol, const Symbol& write_symbol) const {
  for (const auto& transition : transitions_) {
    if (transition.GetSymbol() == read_symbol && transition.GetWriteSymbol() == write_symbol) {
      return true;
    }
  }
  return false;
}

/**
 * @brief Prints all transitions of the state.
 */
void State::PrintTransitions() const {
  for (const auto& transition : transitions_) {
    std::cout << this->GetID() << " " << transition.GetSymbol().GetValue()
              << " " << transition.GetNextState() << " "
              << transition.GetWriteSymbol().GetValue() << " "
              << ToString(transition.GetMovement()) << std::endl;
  }
}
