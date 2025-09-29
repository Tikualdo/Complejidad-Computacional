/**
  * Universidad de La Laguna 
  * Escuela Superior de Ingeniería y Tecnología 
  * Grado en Ingeniería Informática 
  * Complejidad Computacional
  * 
  * @author Paulo Padilla Domingues 
  * @date Sep 25 2025 
  * @brief
  * 
  * Archivo 
  * Historial de revisiones
  *     // 
*/
#include "automaton.hpp"

class FinalAutomaton : public Automaton {
  public:
    FinalAutomaton(const std::string& input_file);
  private:
    State final_state_;
  };
