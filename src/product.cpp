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
#include "../include/product.hpp"

int Product::operate(std::initializer_list<IntOrVector> elements) {
  if (elements.size() != 2) throw std::invalid_argument("\033[1;31mInvalid number of arguments to recursive primitive function 'Product'\033[0m");
  const auto& first_element = *elements.begin();
  const auto& second_element = *(elements.begin() + 1);
  increment_call_count();
  return std::visit([this](auto&& arg1, auto&& arg2) -> int {
    using type1 = std::decay_t<decltype(arg1)>;
    using type2 = std::decay_t<decltype(arg2)>;
    if constexpr (std::is_same_v<type1, int> && std::is_same_v<type2, int>) {
      int operator1 = arg1;
      int operator2 = arg2;

      // BASE CASE: if second operator is zero, return zero
      if (operator2 == 0) return this->zero_.operate({operator2});

      // RECURSIVE CASE: both arguments are non-zero
      return this->add_.operate({operator1, this->operate({operator1, --operator2})});
    } else {
      throw std::invalid_argument("\033[1;31mInvalid argument types in recursive primitive function 'Product'\033[0m");
    }
  }, first_element, second_element);
}
