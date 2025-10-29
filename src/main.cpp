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
            << "======= OPERACIÓN POTENCIA (FPR) =======" 
            << Color::RESET << std::endl;

  while (true) {
    std::cout << Color::CYAN << "Ingrese la base " 
              << Color::DIM << "(-1 para salir): " 
              << Color::RESET;
    std::cin >> base;
    if (base == -1) break;
    if (base < 0) {
      std::cout << Color::BOLD << Color::RED 
                << "  Error: La base debe ser un número entero no negativo." 
                << Color::RESET << std::endl;
      continue;
    }

    std::cout << Color::CYAN << "Ingrese el exponente: " << Color::RESET;
    std::cin >> exp;
    if (exp < 0) {
      std::cout << Color::BOLD << Color::RED 
                << "  Error: El exponente debe ser un número entero no negativo." 
                << Color::RESET << std::endl;
      continue;
    }

    RPF::reset_counts();

    int result = pow.operate({base, exp});
    std::cout << Color::GREEN << "Resultado: " 
              << Color::BOLD << result << Color::RESET << std::endl;
    
    RPF::display_counts();
  }

  std::cout << Color::BOLD << Color::MAGENTA 
            << "\n======= 👋 Fin del Programa =======" 
            << Color::RESET << std::endl;

  return 0;
}