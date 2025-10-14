/**
  * Universidad de La Laguna 
  * Escuela Superior de Ingeniería y Tecnología 
  * Grado en Ingeniería Informática 
  * Complejidad Computacional
  * 
  * @author Paulo Padilla Domingues 
  * @date Oct 14 2025 
  * @brief
  * 
  * Archivo 
  * Historial de revisiones
  *     // 
*/
#pragma once
#include <set>
#include "types.hpp"
#include "transition.hpp"

class State {
  public:
    State(const std::string& id) : id_(id) {}
    State () { id_ = "<>";}
    const std::string& GetID() const { return id_; }
    const std::set<Transition>& GetTransitions() const { return transitions_; }
    void AddTransition(const TransitionParams& params);
    bool HasTransition(const Symbol& read_symbol, const Symbol& write_symbol) const;
    void PrintTransitions() const;
    friend bool operator<(const State& state1, const State& state2) {
      return state1.GetID() < state2.GetID();
    }
  private:
  std::string id_;
  std::set<Transition> transitions_;
};
