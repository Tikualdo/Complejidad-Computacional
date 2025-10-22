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
    virtual void PrintTransitions() const = 0;
    friend bool operator<(const State& state1, const State& state2) {
      return state1.GetID() < state2.GetID();
    }
    friend bool operator==(const State& state1, const State& state2) {
      return state1.GetID() == state2.GetID();
    }
  protected:
    std::string id_;
};
