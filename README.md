# 🧠 Complejidad Computacional  
## Práctica 2 --- Simulador de Máquina de Turing Determinista  

### Datos personales  
- **Nombre:** Paulo Padilla Domingues
- **Correo:** alu0101571836@ull.edu.es
- **Grupo:** PE101
- **Fecha de entrega:** 23 de octubre de 2025  

## 📜 Descripción General

La práctica consiste en implementar un simulador de una máquina de Turing determinista. Se ha desarrollado una clase `MultiTapeTuringMachine` que permite cargar la configuración de la máquina desde un archivo y simular su comportamiento con una entrada dada.  
Además, se ha implementado una extensión adicional que permite trabajar con máquinas multicinta, donde cada cinta tiene un comportamiento independiente pero coordinado por el mismo conjunto de transiciones.

## 📄 Formato del Archivo de Configuración

El fichero de configuración del autómata debe cumplir el siguiente formato:

```bash
# Comentarios (opcional)

q0 q1 q2 q3 q4 q5 q6  # Estados del autómata (Q)
a b                   # Símbolos del lenguaje (Σ)
a b X Y .             # Símbolos de la cinta (Γ)
q0                    # Estado inicial
.                     # Símbolo blanco de la cinta
q6                    # Estado final
1                     # Número de cintas  
q0 a q1 X R           # Transiciones  
...
```

## ⚙️ Tipo de Máquina de Turing implementada

| Característica | Descripción |
|-----------------|--------------|
| **Movimientos** | Se permiten movimientos `L`, `R` y `S` (sin movimiento). |
| **Escritura y movimiento** | Se realizan simultáneamente en cada transición. |
| **Cinta** | Infinita en ambas direcciones. |
| **Número de cintas** | Se ha implementado la versión **multicinta** como extensión adicional. |

## 🧩 Estructura del proyecto  

┣ 📂 CFiles/    
┃ ┣ [MT_1.txt](CFiles/MT_1.txt)  
┃ ┣ [MT_2.txt](CFiles/MT_2.txt)  
┃ ┗ [MT_Ejemplo.txt](CFiles/MT_Ejemplo.txt)  
┣ 📂 include/    
┃ ┣ [alphabet.hpp](include/alphabet.hpp)  
┃ ┣ [color.hpp](include/color.hpp)  
┃ ┣ [multi-tape_state.hpp](include/multi-tape_state.hpp)  
┃ ┣ [multi-tapeTM.hpp](include/multi-tapeTM.hpp)    
┃ ┣ [state.hpp](include/state.hpp)  
┃ ┣ [symbol.hpp](include/symbol.hpp)  
┃ ┣ [tape.hpp](include/tape.hpp)  
┃ ┣ [TM.hpp](include/TM.hpp)  
┃ ┣ [transition.hpp](include/transition.hpp)  
┃ ┗ [types.hpp](include/types.hpp)  
┣ 📂 InputFiles/    
┃ ┣ [input-1.txt](InputFiles/input-1.txt)  
┃ ┣ [input-2.txt](InputFiles/input-2.txt)  
┃ ┗ [input-Ejemplo.txt](InputFiles/input-Ejemplo.txt)  
┣ 📂 src/    
┃ ┣ [main.cpp](src/main.cpp)  
┃ ┣ [multi-tapeTM.cpp](src/multi-tapeTM.cpp)  
┃ ┣ [multi-tape_state.cpp](src/multi-tape_state.cpp)  
┃ ┗ [tape.cpp](src/tape.cpp)  
┗ 🛠️ [CMakeLists.txt](CMakeLists.txt)  

## 🧠 Componentes principales

| Clase | Descripción | Archivo/Ubicación |
|--------|--------------|-----------------|
| `Symbol` | Representa un símbolo del alfabeto de entrada o de cinta. | `symbol.hpp` |
| `Alphabet` | Representa el alfabeto de la máquina de Turing. | `alphabet.hpp` |
| `Movement` | Enumera los posibles movimientos de la cabeza de lectura/escritura. | `types.hpp` |
| `TransitionParams` | Estructura con los parámetros de una transición (`símbolo leído`, `estado siguiente`, `símbolo escrito`, `movimiento`). | `types.hpp` |
| `Transition` | Define una transición concreta de la máquina. | `transition.hpp` |
| `Tape` | Implementa la cinta como una lista doblemente enlazada, con movimientos infinitos a ambos lados. | `tape.hpp` |
| `MultiTapeState` | Representa un estado de la máquina y sus transiciones asociadas. | `state.hpp` |
| `MultiTapeTuringMachine` | Clase principal que simula la ejecución de una Máquina de Turing determinista de varias cintas. | `multi_tape_tm.hpp` |

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

4. Ejecutar el simulador con un fichero de entrada correspondiente a cada autómata por su número:
   ```txt
   ./DETERMINISTIC_TURING_MACHINE_SIMULATOR ../CFiles/MT_X.txt ../InputFiles/input-X.tm
   ```

## 🧪 Ficheros de Configuración Utilizados

Los **ficheros de configuración** de la Máquina de Turing se encuentran en la carpeta `CFiles/`.  
Cada uno define una máquina diferente con su propio lenguaje reconocido.

| Fichero | Descripción | Lenguaje reconocido |
|----------|--------------|---------------------|
| **`CFiles/MT_1.txt`** | Máquina que reconoce cadenas del tipo `aⁿbᵐ` | L = { aⁿbᵐ ∣ m > n, n > 0 } |
| **`CFiles/MT_2.txt`** | Máquina que reconoce cadenas del alfabeto {a, b} y escribe el número de a's y b's con 1's en otra cinta | L = { w ∈ {a,b}* } |

## 💻 Máquinas de Turing en JFLAP
1. MT que reconozca el lenguaje L = { aⁿbᵐ ∣ m > n, n > 0 }
   - ![MT_1f](img/MT_1.png)
2. MT que reciba como parámetro una cadena compuesta por símbolos ‘a’ y ‘b’. La
   MT debe sustituir la cadena por el número de símbolos ‘a’, seguido del número de
   símbolos ‘b’ separados por un símbolo blanco. El número se codificará como n = 1ⁿ⁺¹. Si la cadena está compuesta por símbolos del mismo tipo, se reflejará con un “1” la ausencia del otro símbolo.
   - ![MT_2f](img/MT_2.png)