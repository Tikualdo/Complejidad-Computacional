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
#include "../include/add.hpp"

/**
 * @brief Operates on two elements.
 * @param elements A list of two elements to operate on.
 * @return The result of the addition.
 */
int Add::operate(std::initializer_list<IntOrVector> elements) {
  if (elements.size() != 2) throw std::invalid_argument("\033[1;31mInvalid number of arguments to recursive primitive function 'Add'\033[0m");
  const auto& first_element = *elements.begin();
  const auto& second_element = *(elements.begin() + 1);
  calls_++;
  return std::visit([this](auto&& arg1, auto&& arg2) -> int {
    using type1 = std::decay_t<decltype(arg1)>;
    using type2 = std::decay_t<decltype(arg2)>;

    if constexpr (std::is_same_v<type1, int> && std::is_same_v<type2, int>) {
      int operator1 = arg1;
      int operator2 = arg2;

      if (operator1 < 0 || operator2 < 0) throw std::invalid_argument(
        "\033[1;31mInvalid argument values to recursive primitive function 'Add'. Arguments must be non-negative.\033[0m"
      );

      // BASE CASE: one argument is zero
      if (operator2 == 0) return Projection().operate({1, std::vector<int>{operator1}});

      // RECURSIVE CASE: both arguments are non-zero
      int new_operator2 = --operator2;
      return this->sucesor_.operate({this->projection_.operate({3, std::vector<int>{operator1, new_operator2, this->operate({operator1, new_operator2})}})});
    } else throw std::invalid_argument("\033[1;31mInvalid argument types to recursive primitive function 'Add'\033[0m");
  }, first_element, second_element);
}

void Add::PrintCalls() const {
  std::cout << "Add calls: " << calls_ << std::endl;
  projection_.PrintCalls();
  sucesor_.PrintCalls();
}