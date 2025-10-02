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
#include "automaton.hpp"

class FinalAutomaton : public Automaton {
  public:
    FinalAutomaton(const std::string& input_file);
    State GetFinalState() const { return final_state_; }
    void Print() const;
  private:
    State final_state_;
  };
