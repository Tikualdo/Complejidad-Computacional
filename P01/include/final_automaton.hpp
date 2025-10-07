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
#include <vector>
#include <map>
#include "automaton.hpp"

// Aliases para legibilidad
using TransitionKey = std::tuple<char, char, std::string, std::string>;
using ConfigKey = std::tuple<std::string, std::size_t, std::string>;
using TriedMap = std::map<ConfigKey, std::set<TransitionKey>>;

class FinalAutomaton : public Automaton {
  public:
    FinalAutomaton(const std::string& input_file);
    State GetFinalState() const { return final_state_; }
    void Print() const;
    void Evaluate(const std::string& input_file);
    bool EvaluateString(const std::string& input_strings, const State& current_state, std::size_t pos, TriedMap& tried_map, int);
    State GetStateByID(const std::string& id) const;
  private:
    State final_state_;
};
