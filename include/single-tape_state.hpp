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
#include <optional>
#include "types.hpp"
#include "transition.hpp"
#include "state.hpp"

class SingleTapeState : public State {
  public:
    SingleTapeState(const std::string& id) : State(id) {}
    SingleTapeState () : State("<>") {}
    const std::string& GetID() const { return State::GetID(); }
    const std::set<Transition>& GetTransitions() const { return transitions_; }
    void AddTransition(const TransitionParams& params);
    bool HasTransition(const Symbol& read_symbol, const Symbol& write_symbol) const;
    std::optional<TransitionParams> GetTransition(const Symbol& symbol) const;
    void PrintTransitions() const override;
  private:
    std::set<Transition> transitions_;
};
