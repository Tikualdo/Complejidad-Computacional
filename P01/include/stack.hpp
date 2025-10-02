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
#include <ranges>

/**
 * 
 */
template <typename T>
class Stack {
  public:
    T Top() const {
      if (elements.empty()) throw std::out_of_range("Stack<>::top(): empty stack");
      return elements.back();
    }

    /**
     * @brief Push an element onto the stack.
     * @param element The element to push.
     */
    void Push(const T& element) {
      elements.push_back(element);
    }

    /**
     * @brief Push an array of elements onto the stack.
     * @param elements The array of elements to push.
     */
    template <size_t N>
    void Push(const T (&elements)[N]) {
      for (const auto& elem : elements | std::views::reverse) {
        this->Push(elem);
      }
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
     * @brief Check if the stack is empty.
     * @return True if the stack is empty, false otherwise.
     */
    bool IsEmpty() const {
      return elements.empty();
    }

    /**
     * @brief Print all elements in the stack.
     */
    void Print() const {
      for (const auto& elem : elements | std::views::reverse) {
        std::cout << elem << " ";
      }
      std::cout << std::endl;
    }
  private:
    std::list<T> elements;
};
