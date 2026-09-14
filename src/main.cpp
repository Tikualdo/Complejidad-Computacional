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
#include "../include/projection.hpp"
#include "../include/sucesor.hpp"
#include "../include/zero.hpp"
#include "../include/one.hpp"
#include "../include/add.hpp"
#include "../include/product.hpp"
#include "../include/pow.hpp"
#include "../include/colors.hpp"

int main(int argc, char* argv[]) {
  Pow pow;
  int base, exp;
  std::cout << Color::BOLD << Color::MAGENTA 
            << "======= POWER OPERATION (RPF) =======" 
            << Color::RESET << std::endl;

  while (true) {
    std::cout << Color::CYAN << "Enter the base " 
              << Color::DIM << "(-1 to exit): " 
              << Color::RESET;
    std::cin >> base;
    if (base == -1) break;
    if (base < 0) {
      std::cout << Color::BOLD << Color::RED 
                << "  Error: The base must be a natural number." 
                << Color::RESET << std::endl;
      continue;
    }

    std::cout << Color::CYAN << "Enter the exponent: " << Color::RESET;
    std::cin >> exp;
    if (exp < 0) {
      std::cout << Color::BOLD << Color::RED 
                << "  Error: The exponent must be a natural number." 
                << Color::RESET << std::endl;
      continue;
    }

    RPF::reset_counts();

    int result = pow.operate({base, exp});
    std::cout << Color::GREEN << "Result: " 
              << Color::BOLD << result << Color::RESET << std::endl;
    
    RPF::display_counts();
  }

  std::cout << Color::BOLD << Color::MAGENTA 
            << "\n======= End of program =======" 
            << Color::RESET << std::endl;

  return 0;
}