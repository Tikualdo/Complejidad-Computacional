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
#include "RPF.hpp"

/**
 * @brief Sucesor class
 */
class Sucesor : public RPF {
  public:
    int operate(std::initializer_list<IntOrVector> elements) override;
    const char* get_name() const override { return "Sucesor"; }
};
