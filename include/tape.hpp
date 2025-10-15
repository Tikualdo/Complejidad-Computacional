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
#include "symbol.hpp"

class Tape {
  public:
    Tape(const Symbol& blank_symbol);
    Tape() {}
  private:
    std::list<Symbol> tape_;
    int head_;
};