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
    int GetCalls() const { return calls_; }
    void reset_calls() { zero_.reset_calls(); sucesor_.reset_calls(); }
    void PrintCalls() const;
  private:
    Zero zero_;
    Sucesor sucesor_;
    int calls_ = 0;
};
