# 🖥️ COAAL - Lab 7

In this lab, we implemented an **8086 Assembly Language Program** to perform basic **arithmetic operations** — Addition, Subtraction, Multiplication, and Division — using **emu8086**.

---

## 🎯 Objectives

By the end of this lab, students will be able to:

- Take numeric input from the user in assembly.
- Perform and display results of basic arithmetic operations.
- Use DOS interrupts for input/output handling.
- Work with registers and variables for arithmetic operations.

---

## 📝 Exercise

**Task:**  
Write an assembly language program to perform the four basic arithmetic operations — **Addition**, **Subtraction**, **Multiplication**, and **Division** — according to the following requirements:

### 🔹 Instructions

1. Prompt the user to enter **two numbers**, each on a separate line.  
2. Perform **Addition**, **Subtraction**, **Multiplication**, and **Division** using these inputs.  
3. Display the **result of each operation** clearly.  
4. Use **two variables** for input values and **one variable** for storing the result.

---

## 📂 Key Concepts

- User input and output using `INT 21H`
- ASCII to numeric conversion and vice versa
- Basic arithmetic operations (`ADD`, `SUB`, `MUL`, `DIV`)
- Memory and register data handling in 8086 Assembly
- DOS interrupt functions (`AH = 01H`, `AH = 02H`, `AH = 09H`, `AH = 4CH`)

---

> **Note:**  
> This lab focused on **practical understanding** of user input, output formatting, and performing arithmetic directly through registers and DOS interrupts in assembly.
