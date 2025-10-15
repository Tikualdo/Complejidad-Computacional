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
#include <vector>
#include "symbol.hpp"
#include "tape.hpp"

class TapeManager {
  public:
    TapeManager(const int tapes_size) : tapes_(tapes_size) {}
    TapeManager() : tapes_(1) {}
  private:
    std::vector<Tape> tapes_;
};