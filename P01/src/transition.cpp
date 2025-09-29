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

Transition::Transition(
  const char& string_symbol,
  const char& stack_symbol,
  const std::string& state_symbol,
  const std::string& stack_writing
) {
  transition_ = std::make_tuple(string_symbol, stack_symbol, state_symbol, stack_writing);
}
