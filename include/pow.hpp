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
    int GetCalls() const { return calls_; }
    void AddCall() { calls_++; }
    void reset_calls() { one_.reset_calls(); product_.reset_calls(); }
    void PrintCalls() const;
  private:
    One one_;
    Product product_;
    int calls_ = 0;
};
