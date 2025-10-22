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
#include <vector>
#include <set>
#include <optional>
#include "types.hpp"
#include "transition.hpp"
#include "state.hpp"

class MultiTapeState : public State {
  public:
    MultiTapeState(const std::string& id) : State(id) {}
    MultiTapeState () : State("<>") {}
    const std::string& GetID() const { return State::GetID(); }
    std::set<std::vector<Transition>>& GetTransitions() { return transitions_; }
    void AddTransition(const std::vector<Transition>& transition) { transitions_.insert(transition); }
    bool HasTransition(std::vector<Symbol> read_symbols, std::vector<Symbol> write_symbols) const;
    std::optional<std::vector<Transition>> GetTransition(const std::vector<Symbol>& read_symbols) const;
    virtual void PrintTransitions() const override;
  private:
    std::set<std::vector<Transition>> transitions_;
};
