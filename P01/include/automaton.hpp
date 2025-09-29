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

class Automaton {
  public:
    virtual ~Automaton() = 0;
  protected:
    Alphabet alphabet_;
    Alphabet stack_alphabet_;
    Stack<char> stack_;
    State current_state_;
    std::set<State> states_;
};