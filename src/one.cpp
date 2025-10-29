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
#include "../include/one.hpp"

int One::operate(std::initializer_list<IntOrVector> elements) {
  if (elements.size() != 1) throw std::invalid_argument("\033[1;31mInvalid number of arguments to recursive primitive function 'One'\033[0m");
  increment_call_count();
  const auto& first_element = *elements.begin();
  return std::visit([this](auto&& arg1) -> int {
    using type1 = std::decay_t<decltype(arg1)>;
    if constexpr (std::is_same_v<type1, int>) {
      int result = arg1;
      return this->sucesor_.operate({this->zero_.operate({result})});
    } else {
      throw std::invalid_argument("\033[1;31mInvalid argument types in recursive primitive function 'One'\033[0m");
    }
  }, first_element);
}
