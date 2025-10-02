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
#include "../include/stack.hpp"
#include "../include/final_automaton.hpp"

int main(int argc, char* argv[]) {
  std::string arg1 = argv[1];
  if (argc < 3 && (arg1 != "--help" || arg1 != "-h")) {
    std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
    return 1;
  }
  FinalAutomaton* automaton = new FinalAutomaton(arg1);
  std::string arg2 = argv[2];
  automaton->Evaluate(arg2);
  // automaton->Print();
  return 0;
}
