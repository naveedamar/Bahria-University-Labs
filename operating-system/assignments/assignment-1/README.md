# OS Assignment 01: Student Result Processing System

This assignment demonstrates Inter-Process Communication (IPC) using Pipes and Process Creation using Fork in a Linux environment.

## Problem Statement
Develop a system where a **Child Process** acts as a Data Sender and a **Parent Process** acts as a Result Processor.

### System Workflow
1. **Child Process (Sender):**
   * Takes user input for Student Name and Marks for 3 subjects.
   * Writes this data structure into the pipe.
   * Closes the read end for security and resource management.

2. **Parent Process (Processor):**
   * Reads the data structure from the pipe.
   * Calculates Total Marks, Average, and Grade (A/B/C/Fail).
   * Displays the final formatted result card.
   * Closes the write end to prevent blocking.

---

## Evaluation Logic
* **Total Marks:** Sum of three subjects.
* **Average:** Total / 3.
* **Grading Scale:** * 80+ : A
    * 70+ : B
    * 60+ : C
    * Below 60 : Fail
---

## Requirements
* **Language:** C
* **Environment:** Ubuntu (Linux)
* **System Calls:** `pipe()`, `fork()`, `read()`, `write()`, `close()`

## Compilation and Execution
To compile and run the program in the Ubuntu terminal:

* Navigate to assignment folder
    ```bash
    cd assignment-1

* Compile the C file
    ```bash
    gcc student-result-processing-system.c -o student-result

* Run the program
    ```bash
    ./student-result