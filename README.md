# Recursive Primitive Functions Implementation

## 📜 Descripción General

The objective of this project is to implement a C++ program that calculates the **pow(x, y)**function, treating it as a **Recursive Primitive Function (RPF)**.

The design is purely **object-oriented**, where each primitive function (such as `Add`, `Product`, etc.) is a class that inherits from an abstract base class `RPF`. The program not only calculates the final result but also **counts and displays the total number of calls** to each of the primitive functions used during the computation.

## 🧩 Implemented Recursive Primitive Functions

To build the `pow(x, y)` function, it is necessary to first implement the initial functions and, from them, create more complex functions through composition and recursion. The implemented functions are:

| Function | Mathematical Definition | Dependencies |
| :--- | :--- | :--- |
| **Zero** | `Zero(x) = 0` | - |
| **Sucessor** | `Sucessor(x) = x + 1` | - |
| **Projection** | `Pᵢⁿ(x₁, ..., xₙ) = xᵢ` | - |
| **One** | `One(x) = Sucessor(Zero(x))` | `Zero`, `Sucessor` |
| **Add** | `Add(x, y)` | `Sucessor`, `Projection` |
| **Product** | `Product(x, y)` | `Add`, `Zero` |
| **Power** | `Pow(x, y)` | `Product`, `One` |

## 📂 Project Structure

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

## 🏗️ Compilation, Build, and Execution

To compile the project, the `CMake` build system must be used. To do this, follow these steps:

1. Create a build directory inside the project's root directory:
   ```bash
   mkdir build
   cd build
   ```

2. Run `CMake` to configure the project:
   ```bash
   cmake ..
   ```

3. Compile the project using `make`:
   ```bash
   make
   ```

4. Run the program:
   ```bash
   ./RECURSIVE_PRIMITIVE_FUNCTIONS
   ```

## ⌨️ Input and Output Format

The program works interactively, requesting values via keyboard.

* **Entrada**: Two non-negative integers are requested: the **base** and the **exponent**. To exit the program, `-1` must be entered.

* **Salida**: For each pair of numbers entered, the program will display:
    1. The **result** of the `bᵉ` operation.
    2. A **detailed report** with the number of calls made to each primitive function.

    **Execution example:**
    ```
      ======= POWER OPERATION (RPF) =======
      Enter the base (-1 to exit): 2
      Enter the exponent: 3
      Result: 8
      --- 📊 Function Calls Report ---
        Add        calls: 21
        One        calls: 1
        Pow        calls: 4
        Product    calls: 10
        Projection calls: 21
        Successor  calls: 15
        Zero       calls: 4
      -------------------------------------------
        Total      calls: 76
    ```
