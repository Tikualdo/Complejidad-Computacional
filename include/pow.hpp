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
#include "projection.hpp"
#include "one.hpp"
#include "add.hpp"
#include "product.hpp"

class Pow : public RPF {
  public:
    int operate(std::initializer_list<IntOrVector> elements) override;
    const char* get_name() const override { return "Pow"; }
  private:
    One one_;
    Product product_;
};
