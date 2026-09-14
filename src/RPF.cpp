/**
  * Universidad de La Laguna 
  * Escuela Superior de Ingeniería y Tecnología 
  * Grado en Ingeniería Informática 
  * Complejidad Computacional
  * 
  * @author Paulo Padilla Domingues 
  * @date Oct 26 2025 
  * @brief
  * 
  * Archivo 
  * Historial de revisiones
  *     // 
*/
#include <iostream>
#include <iomanip>
#include "../include/RPF.hpp"
#include "../include/colors.hpp"

/**
 * @brief Displays the call counts for each RPF operation.
 */
void RPF::display_counts() {
  std::cout << Color::BOLD << Color::BLUE 
            << "--- 📊 Function Calls Report ---" 
            << Color::RESET << std::endl;

  if (call_counts.empty()) {
    std::cout << Color::DIM << "No function has been called." 
              << Color::RESET << std::endl;
    return;
  }

  for (const auto& pair : call_counts) {
    std::cout << "  "
              << Color::BRIGHT_CYAN << std::left << std::setw(15) << pair.first
              << Color::DIM << " calls: "
              << Color::RESET << Color::BOLD << Color::BRIGHT_YELLOW << pair.second 
              << Color::RESET << std::endl;
  }
  
  std::cout << Color::BOLD << Color::BLUE
            << "-------------------------------------------"
            << Color::RESET << std::endl;
  int total_calls = 0;
  for (const auto& pair : call_counts) {
    total_calls += pair.second;
  }
  std::cout << "  " 
            << Color::RED << Color::BOLD << std::left << std::setw(15) << "Total"
            << Color::DIM << " calls: "
            << Color::RESET << Color::BOLD << Color::BRIGHT_YELLOW << total_calls
            << Color::RESET << std::endl;
}