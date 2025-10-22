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
#include "single-tape_state.hpp"
#include "tape.hpp"
#include "TM.hpp"

/**
 * @brief Represents a Turing machine.
 */
class SingleTapeTuringMachine : public TuringMachine {
  public:
    SingleTapeTuringMachine(const std::string& config_file_name);
    bool Simulate(const std::string& input) override;
    void CheckInputs(const std::string& input_file_name);
  private:
    std::set<SingleTapeState> states_;
    SingleTapeState initial_state_;
    std::set<SingleTapeState> final_states_;
    Tape tape_;
};
