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
#include "../include/zero.hpp"

/**
 * @brief Operates the Zero function.
 * @param elements The elements to operate on.
 */
int Zero::operate(std::initializer_list<IntOrVector> elements) {
  if (elements.size() != 1) throw std::invalid_argument("\033[1;31mInvalid number of arguments to recursive primitive function 'Zero'\033[0m");
  increment_call_count();
  return 0;
}
