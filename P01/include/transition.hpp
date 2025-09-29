/**
  * Universidad de La Laguna 
  * Escuela Superior de Ingeniería y Tecnología 
  * Grado en Ingeniería Informática 
  * Complejidad Computacional
  * 
  * @author Paulo Padilla Domingues 
  * @date Sep 24 2025 
  * @brief
  * 
  * Archivo 
  * Historial de revisiones
  *     // 
*/
#pragma once
#include <tuple>
#include <string>

class Transition {
  public:
    Transition(const char&, const char&, const std::string&, const std::string&);
    const std::tuple<char, char, std::string, std::string>& GetTransition() const { return transition_; }
    friend bool operator<(const Transition& trans1, const Transition& trans2) {
      return std::get<0>(trans1.GetTransition()) < std::get<0>(trans2.GetTransition());
    }
  private:
    std::tuple<char, char, std::string, std::string> transition_;
};
