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

int main(int argc, char* argv[]) {
  std::cout << "======= OPERACION POTENCIA RPF =======" << std::endl;
  while (true) {
    int base, exp;
    std::cout << "Ingrese la base (o -1 para salir): ";
    std::cin >> base;
    if (base == -1) break;
    std::cout << "Ingrese el exponente: ";
    std::cin >> exp;
    Pow pow;

    // Crear la expresión RPF para la operación de potencia
    std::cout << "Resultado: " << pow.operate({base, exp}) << std::endl;
    pow.PrintCalls();
  }

  return 0;
}
