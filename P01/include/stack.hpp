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
#pragma once
#include <iostream>
#include <list>
#include <stdexcept>

/**
 * 
 */
template <typename T>
class Stack {
  public:
    /**
     * @brief Push an element onto the stack.
     * @param element The element to push.
     */
    void Push(const T& element) {
      elements.push_back(element);
    }

    /**
     * @brief Pop an element from the stack.
     * @return The popped element.
     */
    T Pop() {
      if (elements.empty()) {
        throw std::out_of_range("Stack<>::pop(): empty stack");
      }
      T elem = elements.back();
      elements.pop_back();
      return elem;
    }

    /**
     * @brief Print all elements in the stack.
     */
    void Print() const {
      for (const auto& elem : elements) {
      std::cout << elem << " ";
      }
      std::cout << std::endl;
    }
  private:
    std::list<T> elements;
};