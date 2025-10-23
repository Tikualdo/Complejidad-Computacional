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
#include "../include/colors.hpp"
#include "../include/multi-tapeTM.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
  std::cout << CYAN << BOLD;
  std::cout << "===========================================\n";
  std::cout << "      Máquina de Turing Determinista       \n";
  std::cout << "===========================================\n\n";
  std::cout << RESET;

  if (argc < 3) {
    std::cerr << RED << BOLD << "❌ Error: " << RESET
              << "Se requiere un archivo de configuración y otro de entrada.\n\n";
    std::cout << YELLOW << "Uso correcto: " << RESET
              << "./tm <archivo_config> <archivo_entrada>\n";
    return 1;
  }

  // Mostrar archivo de configuración cargado
  std::string config_file_name = argv[1];
  std::cout << GREEN << "✔ Archivo de configuración detectado: " 
            << RESET << config_file_name << "\n\n";

  // Mensaje interactivo antes de iniciar simulación
  std::cout << MAGENTA << "👉 Presiona " << BOLD << "Enter" << RESET << MAGENTA
            << " para simular la máquina de Turing..." << RESET << "\n";
  std::cin.ignore();

  std::cout << BOLD << CYAN << "=== RESULTADOS DE PRUEBAS ===\n" << RESET;
  MultiTapeTuringMachine tm(config_file_name);
  tm.CheckInputs(argv[2]);

  std::cout << BOLD << CYAN << "\nFin de la simulación\n" << RESET;

  return 0;
}
