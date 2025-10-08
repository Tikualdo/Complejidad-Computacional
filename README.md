# 🧠 Complejidad Computacional  
## Práctica 1 --- Simulador de Autómata con Pila  

### Datos personales  
- **Nombre:** Paulo Padilla Domingues
- **Correo:** alu0101571836@ull.edu.es
- **Grupo:** PE101
- **Fecha de entrega:** - de octubre de 2025  

## 📜 Descripción General

Esta práctica consiste en **implementar un simulador de un Autómata con Pila (AP)**. El simulador permite:

- Leer la definición del autómata desde un fichero de texto.  
- Comprobar múltiples cadenas de entrada.  
- Mostrar si cada cadena **es aceptada o no** por el lenguaje.  
- (Opcional) Ejecutar en **modo traza**, mostrando el proceso paso a paso.

## ⚙️ Tipo de Autómata Implementado

Se ha implementado un **Autómata con Pila (AP)** con aceptación por **estado final (APf)**  

## 📄 Formato del Archivo de Configuración

El fichero de configuración del autómata debe cumplir el siguiente formato:

```bash
# Comentarios (opcional)

q1 q2 q3      # Estados del autómata (Q)
a b           # Símbolos del lenguaje (Σ)
S A           # Símbolos de la pila (Γ)
q1            # Estado inicial
S             # Símbolo inicial de la pila
q3            # Estado final
q1 a S q1 AS  # Transiciones
...
```

## 🧱 Estructura del Código

El proyecto se ha desarrollado siguiendo un diseño **orientado a objetos**, dividiendo la funcionalidad principal en varias clases y ficheros para mejorar la organización y la claridad del código.

Estructura general del proyecto:
```bash
.
├── CFiles # Ficheros de configuración de los automatas (APf, APv, etc.).
├── InputFiles # Ficheros con las cadenas de entrada.
├── include # Archivos de cabecera (.hpp) con las definiciones de clases.
└── src # Código fuente (.cpp) del simulador.
```
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
   ```bash
   ./STACK_AUTOMATON_SIMULATOR ../CFiles/APf-X.txt ../InputFiles/input-X.txt [--debug | -d]
   ```

## 🧪 Ficheros de Configuración Utilizados

Los **ficheros de configuración** del autómata se encuentran en la carpeta `CFiles/`.  
Cada uno define un autómata diferente con su propio lenguaje reconocido.

| Fichero | Descripción | Lenguaje reconocido |
|----------|--------------|---------------------|
| **`CFiles/APf-1.txt`** | Autómata que reconoce cadenas del tipo `aⁿbⁿ` | L = { aⁿbⁿ ∣ n > 0 } |
| **`CFiles/APf-2.txt`** | Autómata que reconoce cadenas palíndromas de longitud par | L = { ww<sup>R</sup> ∣ w ∈ {a,b,c}* donde w<sup>R</sup> es w invertido } |
| **`CFiles/APf-3.txt`** | Autómata que reconoce cadenas del tipo `aⁿbⁿ` | L = { aⁿbⁿ ∣ n ≥ 0 } |
| **`CFiles/APf-4.txt`** | Autómata que reconoce cadenas palíndromas de longitud par | L = { ww<sup>R</sup> ∣ w ∈ {0,1}* donde w<sup>R</sup> es w invertido } |
| **`CFiles/APf-5.txt`** | Autómata que reconoce cadenas del tipo `aⁱbᵗcᵏ` | L = { a<sup>i</sup>b<sup>t</sup>c<sup>k</sup>b ∣ i, t, k ≥ 1} |