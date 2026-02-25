# 🏛️ CSC 327: Computer Architecture - Lab 4

## 🎯 Objective
The objective of this lab was to implement loop structures (`for`, `while`, `do-while`) in MIPS assembly and understand how branching controls repetition.

## 📝 Tasks Completed

### Task 1: Print First 10 Integers
Implemented a loop to print numbers from 1 to 10 using a counter and branch instructions.

### Task 2: Sum of 1 to N
Wrote a program to calculate the sum of integers from 1 to a user-provided number N.

### Task 3: Factorial of N
Calculated the factorial of a number N using iterative multiplication in a loop.

## 🧠 Quiz Answers

**Q1. Which instruction is typically used to decrement a loop counter in MIPS?**
Answer: `addi` (using a negative immediate value).

**Q2. MIPS provides a direct instruction for for loops. (T/F)**
Answer: False

**Q3. In MIPS, loops are implemented using conditional branches and jump instructions.**
Answer: True

**Q4. Describe how a factorial program is implemented using a loop in MIPS.**
Answer: It initializes a result register to 1, then uses a loop to multiply the result by the counter, decrementing the counter until it reaches zero.

## 🚀 Open-Ended Task: Multiplication Table
Created a program to print the multiplication table of a number N up to 10. This involved initializing a counter, performing multiplication in a loop, and formatting the output.

## 🏁 Conclusion
This lab demonstrated how to construct count-controlled loops in MIPS. I learned to safely initialize counters, use branch instructions to set loop boundaries, and manage iterative calculations.