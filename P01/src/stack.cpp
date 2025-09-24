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
#include "../include/stack.hpp"

template <typename T>
void Stack<T>::push(const T& element) {
  elements.push_back(element);
}

template <typename T>
T Stack<T>::pop() {
  if (elements.empty()) {
    throw std::out_of_range("Stack<>::pop(): empty stack");
  }
  T elem = elements.back();
  elements.pop_back();
  return elem;
}
