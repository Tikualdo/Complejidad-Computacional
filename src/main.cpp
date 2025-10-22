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
#include <iostream>
#include <string>
// #include "../include/single-tapeTM.hpp"
#include "../include/multi-tapeTM.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
  std::cout << "===========================================\n";
  std::cout << "      Máquina de Turing Determinista       \n";
  std::cout << "===========================================\n\n";

  if (argc < 3) {
    std::cerr << "Error: Se requiere un archivo de configuración y de entrada.\n";
    return 1;
  }

  std::cout << "Selecciona el tipo de máquina de Turing:\n";
  std::cout << "  1) Cinta simple (Single-tape)\n";
  std::cout << "  2) Multicinta (Multi-tape)\n";
  std::cout << "Opción: ";

  int machine_type;
  std::cin >> machine_type;

  std::cout << "\n=== RESULTADOS DE PRUEBAS ===\n";
  std::string config_file_name = argv[1];
  if (machine_type == 1) {
    // SingleTapeTuringMachine tm(config_file_name);
    // tm.CheckInputs(argv[2]);
  } else if (machine_type == 2) {
    MultiTapeTuringMachine tm(config_file_name);
    // tm.Simulate(argv[2]);
    tm.CheckInputs(argv[2]);
  } else {
    std::cout << "\nOpción no válida. Saliendo...\n";
    return 1;
  }
  return 0;
}
