# 🧠 COAAL - Mid Lab Exam  
### Smart Temperature Monitoring System (8086 Assembly)

---

## 🎯 Objective  
To simulate a **smart temperature monitoring system** using **8086 assembly language**, where the program compares the current temperature with a predefined safe threshold and triggers an alert if the temperature exceeds the limit.

---

## 🧩 Problem Description  

A student is developing a **Smart Temperature Monitoring System** that continuously checks temperature readings. The program:  
1. Declares variables for **current temperature**, **threshold**, and an **alert message**.  
2. Uses general-purpose registers (**AX**, **BX**, **CX**, **DX**) to temporarily store and manipulate temperature values.  
3. Employs various **addressing modes** to efficiently access and update data in memory.  
4. Uses arithmetic instructions (`ADD`, `SUB`, `CMP`) to compare the current temperature with the threshold.  
5. Uses a **conditional jump instruction** to trigger an alert if the temperature exceeds or equals the threshold.  
6. Repeats the process to simulate real-time temperature monitoring.  

---

## 🧠 Conceptual Explanation  

The program demonstrates the use of:  
- **Data comparison** using the `CMP` instruction.  
- **Conditional branching** (`JGE`, `JL`, etc.) to determine program flow.  
- **Memory access and register operations** for handling sensor values.  
- **Message display using interrupts (INT 21H)** to simulate alerts.  

When the current temperature is **greater than or equal** to the threshold, an **alert message** (“Temperature Exceeded”) is displayed. Otherwise, the program continues normal execution without triggering an alert.

---

## ⚙️ Key Concepts  

- Data declaration and initialization in `.DATA` segment  
- Conditional jumps for decision-making  
- Use of registers for intermediate calculations  
- Comparison and branching with `CMP` and `Jxx`  
- Displaying messages with DOS interrupt `INT 21H`  

---

## 🧾 Expected Output  

| Current Temp | Threshold | Output Message             |
|---------------|------------|----------------------------|
| 25            | 30         | Safe Temperature           |
| 35            | 30         | Temperature Exceeded!      |

---

## 🧩 Outcome  

By completing this task, students will:  
- Understand **conditional control flow** in assembly programming.  
- Learn how to use **comparison and branching** to simulate decision-making.  
- Be able to design simple **real-time monitoring logic** using 8086 assembly.  
