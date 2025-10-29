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
#pragma once
#include <vector>
#include <variant>
#include <initializer_list>
#include <stdexcept>

using IntOrVector = std::variant<int, std::vector<int>>;

/**
 * Base class for Recursive Primitive Recursive Functions
 */
class RPF {
  public:
    virtual int operate(std::initializer_list<IntOrVector> elements) = 0;  
};
