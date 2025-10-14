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
#include "symbol.hpp"

/**
 * @brief Represents the movement direction of the tape head.
 */
enum class Movement {
  LEFT,
  RIGHT,
  STAY
};

/**
 * @brief Struct that holds the parameters for a transition in a Turing machine.
 * @param read_symbol The symbol to read from the tape.
 * @param next_state The state to transition to.
 * @param write_symbol The symbol to write to the tape.
 * @param movement The movement direction (left, right or stay).
 */
struct TransitionParams {
    Symbol read_symbol;
    std::string next_state;
    Symbol write_symbol;
    Movement movement;

    bool operator<(const TransitionParams& other) const {
      return std::tie(read_symbol, next_state, write_symbol, movement) < 
             std::tie(other.read_symbol, other.next_state, other.write_symbol, other.movement);
    }
};
