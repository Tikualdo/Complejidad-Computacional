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
#include <iostream>
#include <string>
#include <set>
#include "transition.hpp"
#include "symbol.hpp"

/**
 * @brief Represents a state in the automaton.
 */
class State {
  public:
    State(const std::string& id) : id_(id) {}
    State () { id_ = "<>";}
    void AddTransition(
      const char& string_symbol,
      const char& stack_symbol,
      const std::string& state_symbol,
      const std::string& stack_writing
    );
    std::set<Transition> GetTransitions() const { return transitions; }
    std::string GetID() const { return id_; }
    bool HasTransition(const Symbol& string_symbol, const Symbol& stack_symbol) const;
    // Transition GetTransition(const Symbol& string_symbol, const Symbol& stack_symbol) const;
    void PrintIterations() const;
    friend bool operator<(const State& state1, const State& state2) {
      return state1.id_ < state2.id_;
    }
  private:
    std::string id_;
    std::set<Transition> transitions;
};
