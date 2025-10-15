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
#include "multi-tape_state.hpp"
#include "tape.hpp"
#include "TM.hpp"

/**
 * @brief Represents a Turing machine.
 */
class MultiTapeTuringMachine : public TuringMachine {
  public:
    MultiTapeTuringMachine(const std::string& config_file_name);
    bool Simulate(const std::string& input_file_name);
  private:
    std::set<MultiTapeState> states_;
    MultiTapeState initial_state_;
    std::set<MultiTapeState> final_states_;
    Tape tape_;
};