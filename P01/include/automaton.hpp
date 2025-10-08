/**
  * Universidad de La Laguna 
  * Escuela Superior de Ingeniería y Tecnología 
  * Grado en Ingeniería Informática 
  * Complejidad Computacional
  * 
  * @author Paulo Padilla Domingues 
  * @date Sep 25 2025 
  * @brief
  * 
  * Archivo 
  * Historial de revisiones
  *     // 
*/
#pragma once
#include "alphabet.hpp"
#include "stack.hpp"
#include "state.hpp"

/**
 * @brief Abstract base class for finite automata.
 */
class Automaton {
  public:
    virtual ~Automaton() = 0;
  protected:
    Alphabet alphabet_;
    Alphabet stack_alphabet_;
    Stack<char> stack_;
    char initial_stack_symbol_;
    State initial_state_;
    std::set<State> states_;
};
