# 🏛️ CSC 327: Computer Architecture - Lab 5

## 🎯 Objective
Understand MIPS Load/Store architecture and memory-to-register data transfer.

## 📝 Tasks Completed
* **Task 1: Load and Print:** Loaded a constant from `.data` using `lw` and printed it.
* **Task 2: Store and Retrieve:** Saved user input to RAM using `sw` and retrieved it.
* **Task 3: Swap Variables:** Swapped two memory variables using temporary CPU registers.
* **Open-Ended Task:** Read user inputs, stored them in RAM, computed their sum, and stored the result back to memory.

## 🧠 Quiz Answers
* **Q1:** `lw`
* **Q2:** Main memory at the location labeled `var`.
* **Q3:** False. (Loads an immediate value into a register).
* **Q4:** `la` gets the memory address; `lw` reads the actual data at that address.

## 🚀 Open-Ended Task: Registers vs. Memory
The ALU only calculates using the 32 CPU registers. We must use `lw` to fetch data from RAM and `sw` to save results back.

## 🏁 Conclusion
Learned the core Load/Store principles of MIPS, safely transferring data between CPU registers and main memory for calculations.