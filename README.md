# Pushdown Automaton Simulator  

## 📜 Descripción General

This project implements a **Pushdown Automaton (PDA) Simulator**. The simulator allows users to:

- Read the automaton's definition from a text file.  
- Evaluate multiple input strings.  
- Determine whether each string is **accepted or rejected** by the specified language.  
- (Optional) Run in **trace mode** to display the step-by-step execution process.

## ⚙️ Automaton Type

The implemented model is a **Pushdown Automaton (PDA)** that accepts by **final state**.  

## 📄 Configuration File Format

The automaton's configuration file must follow this exact structure:

```bash
q1 q2 q3      # Automaton states (Q)
a b           # Language alphabet (Σ)
S A           # Stack alphabet (Γ)
q1            # Initial state
S             # Initial stack symbol
q3            # Final state
q1 a S q1 AS  # Transitions
...
```

## 🧱 Project Structure

The software is built using an object-oriented design, dividing the core functionality into distinct classes to improve code organization and clarity.

Estructura general del proyecto:
```bash
.
├── CFiles      # Automaton configuration files.
├── InputFiles  # Input text files with the strings to evaluate.
├── include     # Header files (.hpp) with class definitions.
└── src         # Simulator source code (.cpp).
```
## 🏗️ Build & Execution

The project uses `CMake` as its build system. Follow these steps to compile and run:

1. Create a build directory in the project root:
   ```bash
   mkdir build
   cd build
   ```

2. Run CMake to configure the project:
   ```bash
   cmake ..
   ```

3. Compile the code using `make`:
   ```bash
   make
   ```

4. Run the simulator by passing a configuration file and an input file as arguments:
   ```txt
   ./STACK_AUTOMATON_SIMULATOR ../CFiles/APf-X.txt ../InputFiles/input-X.txt [--debug | -d]
   ```

## 🧪 Provided Configuration Files

Several predefined automaton configuration files are available in the `CFiles/`directory. Each file models an automaton for a specific formal language.

| File | Description | Recognized Language |
|----------|--------------|---------------------|
| **`CFiles/APf-1.txt`** | Recognizes `aⁿbⁿ` strings | L = { aⁿbⁿ ∣ n > 0 } |
| **`CFiles/APf-2.txt`** | Recognizes even-length palindromes | L = { ww<sup>R</sup> ∣ w ∈ {a,b,c}* where w<sup>R</sup> is w reversed } |
| **`CFiles/APf-3.txt`** | Recognizes `aⁿbⁿ` strings (including empty) | L = { aⁿbⁿ ∣ n ≥ 0 } |
| **`CFiles/APf-4.txt`** | Recognizes binary even-length palindromes | L = { ww<sup>R</sup> ∣ w ∈ {0,1}* where w<sup>R</sup> is w reversed } |
| **`CFiles/APf-5.txt`** | Recognizes `aⁱbᵗcᵏ` sequences | L = { a<sup>i</sup>b<sup>t</sup>c<sup>k</sup>b ∣ i, t, k ≥ 1} |
