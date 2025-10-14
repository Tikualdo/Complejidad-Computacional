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
#include <tuple>
#include "types.hpp"

/**
 * @brief Class representing a transition in the automaton.
 */
class Transition {
  public:
    Transition(const TransitionParams& params) : params_(params) {}
    const TransitionParams& GetTransition() const { return params_; }
    const Symbol GetSymbol() const { return params_.read_symbol; }
    const std::string GetNextState() const { return params_.next_state; }
    const Symbol GetWriteSymbol() const { return params_.write_symbol; }
    const Movement GetMovement() const { return params_.movement; }
    friend bool operator<(const Transition& trans1, const Transition& trans2) {
      return (trans1.GetTransition() < trans2.GetTransition());
    }
  private:
    TransitionParams params_;
};
