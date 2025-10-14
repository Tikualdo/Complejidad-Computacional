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
#include "alphabet.hpp"
#include "transition.hpp"
#include "state.hpp"

/**
 * @brief Represents a Turing machine.
 */
class TuringMachine {
  public:
    TuringMachine(const std::string& config_file_name);
    bool Simulate(const std::string& input_file_name);
  private:
    std::set<State> states_;
    Alphabet input_symbols_alphabet_;
    Alphabet tape_symbols_alphabet_;
    State initial_state_;
    Symbol blank_symbol_;
    std::set<State> final_states_;
    std::set<Transition> transitions_;
};