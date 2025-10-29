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
#include "../include/projection.hpp"

/**
 * @brief Operates the projection function on the given elements.
 * @param elements The elements to operate on.
 * @return The result of the projection operation.
 */
int Projection::operate(std::initializer_list<IntOrVector> elements) {
  if (elements.size() != 2) throw std::invalid_argument("\033[1;31mInvalid number of arguments to recursive primitive function 'Projection'\033[0m");
  const auto& first_element = *elements.begin();
  const auto& second_element = *(elements.begin() + 1);
  increment_call_count();
  return std::visit([](auto&& arg1, auto&& arg2) -> int {
    using type1 = std::decay_t<decltype(arg1)>;
    using type2 = std::decay_t<decltype(arg2)>;
    if constexpr (std::is_same_v<type1, int> && std::is_same_v<type2, std::vector<int>>) {
      int index = arg1;
      std::vector<int> vector = arg2;
      if (index <= 0 || index > vector.size()) throw std::out_of_range("\033[1;31mIndex out of range in recursive primitive function 'Projection'\033[0m");
      return vector[index - 1];
    } else {
      throw std::invalid_argument("\033[1;31mInvalid argument types in recursive primitive function 'Projection'\033[0m");
    }
  }, first_element, second_element);
}
