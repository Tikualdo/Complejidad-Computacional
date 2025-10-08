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
#include <tuple>
#include <string>

/**
 * @brief Class representing a transition in the automaton.
 */
class Transition {
  public:
    Transition(const char&, const char&, const std::string&, const std::string&);
    const std::tuple<char, char, std::string, std::string>& GetTransition() const { return transition_; }
    const char GetSymbol() const { return std::get<0>(transition_); }
    const char GetStackSymbol() const { return std::get<1>(transition_); }
    const std::string GetNextState() const { return std::get<2>(transition_); }
    const std::string GetStackWrite() const { return std::get<3>(transition_); }
    bool EvaluateTransition(const char&, const char&) const;
    friend bool operator<(const Transition& trans1, const Transition& trans2) {
      return (trans1.GetTransition() < trans2.GetTransition());
    }
  private:
    std::tuple<char, char, std::string, std::string> transition_;
};
