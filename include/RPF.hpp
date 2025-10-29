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
#include <map>
#include <variant>
#include <initializer_list>
#include <stdexcept>

using IntOrVector = std::variant<int, std::vector<int>>;

/**
 * @brief Base class for Recursive Primitive Recursive Functions
 */
class RPF {
  public:
    inline static std::map<std::string, int> call_counts;
    virtual int operate(std::initializer_list<IntOrVector> elements) = 0;
    virtual const char* get_name() const = 0;
    static void reset_counts() { call_counts.clear(); }
    static void display_counts();
  protected:
    void increment_call_count() { call_counts[get_name()]++; }
};
