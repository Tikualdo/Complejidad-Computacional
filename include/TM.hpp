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
#include <string>
#include "alphabet.hpp"

/**
 * @brief Represents a Turing machine.
 */
class TuringMachine {
  public:
    virtual bool Simulate(const std::string& input_file_name) = 0;
  protected:
    Alphabet input_symbols_alphabet_;
    Alphabet tape_symbols_alphabet_;
    Symbol blank_symbol_;
};