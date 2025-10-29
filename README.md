# 🧠 Complejidad Computacional
## Práctica 3 --- Implementación de Funciones Primitivas Recursivas

### Datos personales
- **Nombre:** Paulo Padilla Domingues
- **Correo:** alu0101571836@ull.edu.es
- **Grupo:** PE101
- **Fecha de entrega:** 30 de octubre de 2025

## 📜 Descripción General

El objetivo de esta práctica es implementar un programa en C++ que calcule la función **potencia(x, y)**, tratándola como una **Función Primitiva Recursiva (FPR)**.

El diseño es puramente **orientado a objetos**, donde cada función primitiva (como `Suma`, `Producto`, etc.) es una clase que hereda de una clase base abstracta `RPF`. El programa no solo calcula el resultado final, sino que también **contabiliza y muestra el número total de llamadas** a cada una de las funciones primitivas utilizadas durante el cómputo.

## 🧩 Funciones Primitivas Recursivas Implementadas

Para construir la función `potencia(x, y)`, es necesario implementar primero las funciones iniciales y, a partir de ellas, crear funciones más complejas mediante composición y recursión. Las funciones implementadas son:

| Función | Definición Matemática | Dependencias |
| :--- | :--- | :--- |
| **Zero** | `Zero(x) = 0` | - |
| **Sucesor** | `Sucesor(x) = x + 1` | - |
| **Proyección** | `Pᵢⁿ(x₁, ..., xₙ) = xᵢ` | - |
| **One** | `One(x) = Sucesor(Zero(x))` | `Zero`, `Sucesor` |
| **Suma** | `Add(x, y)` | `Sucesor`, `Proyección` |
| **Producto** | `Product(x, y)` | `Suma`, `Zero` |
| **Potencia** | `Pow(x, y)` | `Producto`, `One` |

## 📂 Estructura del proyecto

┣ 📂 include/    
┃ ┣ [add.hpp](include/add.hpp)  
┃ ┣ [colors.hpp](include/colors.hpp)  
┃ ┣ [one.hpp](include/one.hpp)  
┃ ┣ [pow.hpp](include/pow.hpp)    
┃ ┣ [product.hpp](include/product.hpp)  
┃ ┣ [projection.hpp](include/projection.hpp)  
┃ ┣ [RPF.hpp](include/RPF.hpp)  
┃ ┣ [sucesor.hpp](include/sucesor.hpp)  
┃ ┗ [zero.hpp](include/zero.hpp)   
┣ 📂 src/    
┃ ┣ [add.cpp](src/add.cpp)  
┃ ┣ [main.cpp](src/main.cpp)  
┃ ┣ [one.cpp](src/one.cpp)  
┃ ┣ [pow.cpp](src/pow.cpp)  
┃ ┣ [product.cpp](src/product.cpp)  
┃ ┣ [projection.cpp](src/projection.cpp)  
┃ ┣ [RPF.cpp](src/RPF.cpp)  
┃ ┣ [sucesor.cpp](src/sucesor.cpp)  
┃ ┗ [zero.cpp](src/zero.cpp)  
┗ 🛠️ [CMakeLists.txt](CMakeLists.txt)  

## 🏗️ Compilación, build y ejecución

Para compilar el proyecto, se debe utilizar el sistema de construcción `CMake`. Para ello, se debe hacer lo siguiente:

1. Crear un directorio de construcción dentro del directorio raíz del proyecto:
   ```bash
   mkdir build
   cd build
   ```

2. Ejecutar `CMake` para configurar el proyecto:
   ```bash
   cmake ..
   ```

3. Compilar el proyecto utilizando `make`:
   ```bash
   make
   ```

4. Ejecutar el programa
   ```bash
   ./RECURSIVE_PRIMITIVE_FUNCTIONS
   ```

## ⌨️ Formato de Entrada y Salida

El programa funciona de manera interactiva, solicitando los valores por teclado.

* **Entrada**: Se solicitan dos números enteros no negativos: la **base** y el **exponente**. Para finalizar el programa, se debe introducir `-1`.

* **Salida**: Por cada par de números introducidos, el programa mostrará:
    1. El **resultado** de la operación `bᵉ`.
    2. Un **reporte detallado** con el número de llamadas realizadas a cada función primitiva.

    **Ejemplo de ejecución:**
    ```
    ======= OPERACIÓN POTENCIA (FPR) =======
    Ingrese la base (-1 para salir): 2
    Ingrese el exponente: 3
    Resultado: 8
    --- 📊 Reporte de Llamadas a Funciones ---
      Add        calls: 21
      One        calls: 1
      Pow        calls: 4
      Product    calls: 10
      Projection calls: 21
      Sucesor    calls: 15
      Zero       calls: 4
    -------------------------------------------
    ```