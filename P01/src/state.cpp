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
void State::PrintIterations() const {
  for (const auto& transition : transitions) {
    std::cout << "\t" << std::get<0>(transition.GetTransition()) 
    << " " << std::get<1>(transition.GetTransition())
    << " " << std::get<2>(transition.GetTransition())
    << " " << std::get<3>(transition.GetTransition()) << std::endl;
  }
}

/**
 * @brief Check if the state has a specific transition.
 * @param string_symbol The input symbol.
 * @param stack_symbol The stack symbol.
 */
bool State::HasTransition(const Symbol& string_symbol, const Symbol& stack_symbol) const {
  for (const auto& transition : transitions) {
    if (std::get<0>(transition.GetTransition()) == string_symbol.GetValue() &&
        std::get<1>(transition.GetTransition()) == stack_symbol.GetValue()) return true;
  }
  return false;
}

// Transition State::GetTransition(const Symbol& string_symbol, const Symbol& stack_symbol) const {
//   for (const auto& transition : transitions) {
    
//   }
// }