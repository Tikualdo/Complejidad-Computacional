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
#include <list>
#include "types.hpp"
#include "symbol.hpp"

class Tape {
  public:
    Tape(const Symbol& blank_symbol);
    Tape() {}
    const std::list<Symbol>& GetTapeContents() const { return tape_; }
    void WriteSymbol(const Symbol& symbol);
    void MoveHead(Movement move);
    void AddWord(const std::string& word);
    void ResetHead() { head_ = 1; }
    void FormatTape();
    void ClearTape();
    void PrintTape() const;
  private:
    void PushFront(const Symbol& symbol) { tape_.push_front(symbol); }
    void PushBack(const Symbol& symbol) { tape_.push_back(symbol); }
    std::list<Symbol> tape_;
    int head_;
    Symbol blank_symbol_;
};