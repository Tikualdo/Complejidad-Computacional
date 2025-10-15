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
#include "state.hpp"

class MultiTapeState : public State {
  public:
    MultiTapeState(const std::string& id) : State(id) {}
    MultiTapeState () : State("<>") {}
    const std::string& GetID() const { return State::GetID(); }
    virtual void PrintTransitions() const override;
  private:
    std::set<Transition> transitions_;
};
