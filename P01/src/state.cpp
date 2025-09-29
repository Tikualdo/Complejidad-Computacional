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
#include "../include/state.hpp"


/**
 * @brief Add a transition to the state.
 */
void State::AddTransition(
  const char& string_symbol,
  const char& stack_symbol,
  const std::string& state_symbol,
  const std::string& stack_writing
) {
  Transition transition(string_symbol, stack_symbol, state_symbol, stack_writing);
  transitions.emplace(transition);
}

/**
 * @brief Print the state and its transitions.
 */
void State::Print() const {
  std::cout << "State ID: " << id_ << std::endl;
  std::cout << "Transitions:" << std::endl;
  for (const auto& transition : transitions) {
    std::cout << "\t" << std::get<0>(transition.GetTransition()) 
    << " --" << std::get<1>(transition.GetTransition())
    << "--> " << std::get<2>(transition.GetTransition())
    << " [label=\"" << std::get<3>(transition.GetTransition()) << "\"]" << std::endl;
  }
}
