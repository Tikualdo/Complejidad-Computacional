/**
  * Universidad de La Laguna 
  * Escuela Superior de Ingeniería y Tecnología 
  * Grado en Ingeniería Informática 
  * Complejidad Computacional
  * 
  * @author Paulo Padilla Domingues 
  * @date Sep 24 2025 
  * @brief
  * 
  * Archivo 
  * Historial de revisiones
  *     // 
*/
#include "../include/transition.hpp"

/**
 * @brief Construct a new Transition object.
 * @param string_symbol The input string for the transition.
 * @param stack_symbol The stack symbol for the transition.
 * @param state_symbol The next state for the transition.
 * @param stack_writing The stack writing for the transition.
 */
Transition::Transition(
  const char& string_symbol,
  const char& stack_symbol,
  const std::string& state_symbol,
  const std::string& stack_writing
) {
  transition_ = std::make_tuple(string_symbol, stack_symbol, state_symbol, stack_writing);
}

/**
 * @brief Evaluate the transition for a given input symbol and stack symbol.
 * @param input_symbol The input symbol to evaluate.
 * @param stack_symbol The stack symbol to evaluate.
 */
bool Transition::EvaluateTransition(const char& input_symbol, const char& stack_symbol) const {
  return std::get<0>(transition_) == input_symbol && std::get<1>(transition_) == stack_symbol;
}