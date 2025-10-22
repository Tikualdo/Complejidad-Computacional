/**
  * Universidad de La Laguna 
  * Escuela Superior de Ingeniería y Tecnología 
  * Grado en Ingeniería Informática 
  * Complejidad Computacional
  * 
  * @author Paulo Padilla Domingues 
  * @date Oct 15 2025 
  * @brief
  * 
  * Archivo 
  * Historial de revisiones
  *     // 
*/
#include <iostream>
#include "tape.hpp"

/**
 * @brief Constructs a tape with the specified blank symbol.
 * @param blank_symbol The symbol to use as the blank symbol.
 */
Tape::Tape(const Symbol& blank_symbol) {
  blank_symbol_ = blank_symbol;
  tape_.push_back(blank_symbol_);
  tape_.push_back(blank_symbol_);
  tape_.push_back(blank_symbol_);
  head_ = 1;
}

/**
 * @brief Writes a symbol to the tape at the current head position.
 * @param symbol The symbol to write to the tape.
 */
void Tape::WriteSymbol(const Symbol& symbol) {
  auto it = std::next(tape_.begin(), head_);
  if (it != tape_.end()) {
    *it = symbol;
  }
}

/**
 * @brief Moves the tape head in the specified direction.
 * @param move The direction to move the tape head.
 */
void Tape::MoveHead(Movement move) {
  if (move == Movement::LEFT) {
    // std::cout << "L " << head_;
    if (head_ == 1) {
      tape_.push_front(blank_symbol_);
    } else head_--;
    // std::cout << " " << head_ << std::endl;
  } else if (move == Movement::RIGHT) {
    // std::cout << "R " << head_;
    if (head_ == tape_.size() - 2) {
      tape_.push_back(blank_symbol_);
      head_++;
    } else head_++;
    // std::cout << " " << head_ << std::endl;
  }
}

/**
 * @brief Adds a word to the tape at the current head position.
 * @param word The word to add to the tape.
 */
void Tape::AddWord(const std::string& word) {
  tape_.clear();
  tape_.push_back(blank_symbol_);
  head_ = 1;
  for (char character : word) {
    auto it = std::next(tape_.begin(), head_);
    tape_.insert(it, Symbol(character));
    head_++;
  }
  head_ = 1;
  tape_.push_back(blank_symbol_);
}

void Tape::PrintTape() const {
  int counter = 0;
  for (const Symbol& symbol : tape_) {
    if (counter == head_) {
      std::cout << "[" << symbol.GetValue() << "]";
    } else {
      std::cout << symbol.GetValue();
    }
    counter++;
  }
  std::cout << std::endl;
}