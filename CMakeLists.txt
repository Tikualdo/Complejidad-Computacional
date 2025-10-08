cmake_minimum_required(VERSION 3.1)

project(comparador_productos_main
    VERSION 1.0
    DESCRIPTION "Comparador de producctos matriciales"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -fsanitize=address -fno-omit-frame-pointer")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR}/include)

# Lista de archivos fuente
set(SOURCES
    src/main.cpp
    src/transition.cpp
    src/state.cpp
    src/automaton.cpp
    src/final_automaton.cpp
)

# Crear el ejecutable
add_executable(STACK_AUTOMATON_SIMULATOR ${SOURCES})