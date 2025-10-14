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

/**
 * @brief Class representing a symbol in the automaton.
 */
class Symbol {
  public:
    Symbol(char value) : value_(value) {}
    char GetValue() const { return value_; }
    friend bool operator<(const Symbol& symbol1, const Symbol& symbol2) {
      return symbol1.GetValue() < symbol2.GetValue();
    }
    friend bool operator==(const Symbol& symbol1, const Symbol& symbol2) {
      return symbol1.GetValue() == symbol2.GetValue();
    }
  private:
    char value_;
};
