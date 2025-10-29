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
#include "zero.hpp"
#include "sucesor.hpp"

class One : public RPF {
  public:
    int operate(std::initializer_list<IntOrVector> elements) override;
    const char* get_name() const override { return "One"; }
  private:
    Zero zero_;
    Sucesor sucesor_;
};
