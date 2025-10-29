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
#include <string>

// --- Definiciones de Colores ANSI ---
namespace Color {
  const std::string RESET     = "\033[0m";
  const std::string BOLD      = "\033[1m";
  const std::string DIM       = "\033[2m";
  
  // Colores de texto normales
  const std::string RED       = "\033[31m";
  const std::string GREEN     = "\033[32m";
  const std::string YELLOW    = "\033[33m";
  const std::string BLUE      = "\033[34m";
  const std::string MAGENTA   = "\033[35m";
  const std::string CYAN      = "\033[36m";
  
  // Colores de texto brillantes (más intensos)
  const std::string BRIGHT_YELLOW = "\033[93m";
  const std::string BRIGHT_CYAN   = "\033[96m";
}