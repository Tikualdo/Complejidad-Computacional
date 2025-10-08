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
#include <fstream>
#include <sstream>
#include "../include/stack.hpp"
#include "../include/final_automaton.hpp"

int main(int argc, char* argv[]) {
  std::string arg1 = argv[1];
  if (argc < 3 && (arg1 != "--help" || arg1 != "-h")) {
    std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
    return 1;
  }
  FinalAutomaton* automaton = new FinalAutomaton(arg1);
  std::string input_file_name = argv[2];
  std::ifstream input_file(input_file_name);
  if (!input_file) {
    std::cerr << "Error opening input file: " << input_file_name << std::endl;
    return 1;
  }
  bool debug_mode = false;
  std::string line;
  if (argc > 3) {
    line = argv[3];
    if (line == "--debug" || line == "-d") {
      debug_mode = true;
    }
  }
  std::cout << "=== RESULTADOS DE PRUEBA ===\n";
  while (std::getline(input_file, line)) {
    std::stringstream flujo(line);
    std::string word;
    if (flujo >> word) {
      automaton->Evaluate(word, debug_mode);
      if (debug_mode) std::cout << "\n";
    } else throw std::runtime_error("Failed to read word from input line");
  }
  return 0;
}
