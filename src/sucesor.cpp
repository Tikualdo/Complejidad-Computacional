/**
  * Universidad de La Laguna 
  * Escuela Superior de Ingeniería y Tecnología 
  * Grado en Ingeniería Informática 
  * Complejidad Computacional
  * 
  * @author Paulo Padilla Domingues 
  * @date Oct 26 2025 
  * @brief
  * 
  * Archivo 
  * Historial de revisiones
  *     // 
*/
#include <iostream>
#include "../include/sucesor.hpp"

/**
 * @brief Operates the Sucesor function.
 * @param elements The elements to operate on.
 * @return The result of the operation.
 */
int Sucesor::operate(std::initializer_list<IntOrVector> elements) {
  if (elements.size() != 1) throw std::invalid_argument("\033[1;31mInvalid number of arguments to recursive primitive function 'Sucesor'\033[0m");
  calls_++;
  return std::visit([](auto&& arg) -> int {
    using T = std::decay_t<decltype(arg)>;
    if constexpr (std::is_same_v<T, int>) {
      return arg + 1;
    } else {
      throw std::invalid_argument("\033[1;31mInvalid argument type to recursive primitive function 'Sucesor'\033[0m");
    }
  }, *elements.begin());
}

void Sucesor::PrintCalls() const {
  std::cout << "Sucesor calls: " << calls_ << std::endl;
}
