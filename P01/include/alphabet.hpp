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
#include <set>
#include "symbol.hpp"

/**
 * @brief Represents the alphabet of the automaton.
 */
class Alphabet {
  public:
    Alphabet() { symbols_.emplace('.'); }
    void AddSymbol(char symbol) { symbols_.emplace(symbol); }
    const std::set<Symbol>& GetSymbols() const { return symbols_; }
    bool IsSymbolPresent(char symbol) const { return symbols_.find(symbol) != symbols_.end(); }
  private:
    std::set<Symbol> symbols_;
};
