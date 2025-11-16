# 🖥️ COAAL – Lab 8

In this lab, we worked with **arrays** in **8086 Assembly Language**, focusing on printing array elements, printing both indexes and values, and taking user input to insert into an array and calculating their sum.

---

## 🎯 Objectives

By the end of this lab, students will be able to:

* **Create and use arrays** in assembly language.
* **Access and display array values** using indexed addressing.
* **Print values on separate lines** using DOS interrupts.
* **Take limited user input** and store it inside an array.
* **Perform summation** on array elements entered by the user.
* Use loops, procedures, and **ASCII–numeric conversions** effectively.

---

## 📝 Exercises

### Exercise 1:
Write a program using an array to print each of its values on a separate line.
### Exercise 2:
Write a program to print array values along with their index numbers, each on a separate line.
### Exercise 3:
Write a program to:
1.  Take **3 user inputs** (range: 1–3)
2.  Store them in an **array**
3.  Compute the **sum** of these numbers
4.  **Display the result** on the console

---

## 📂 Key Concepts

| Concept | Description |
| :--- | :--- |
| **Array declaration and element access** | Defining data blocks (`DB`) and retrieving values from them. |
| **Indexed addressing** | Using the **Source Index ($\mathbf{SI}$)** register to point to array elements. |
| **Input/output (I/O)** | Using **DOS interrupts** (`01H` for input, `02H` for character output, `09H` for string output). |
| **Looping** | Using the $\mathbf{CX}$ register and the `LOOP` instruction to traverse arrays. |
| **ASCII $\leftrightarrow$ numeric conversions** | Subtracting/adding `'0'` (`30H`) to convert between character input/output and binary arithmetic. |
| **Summation** | Accumulating element values into a general-purpose register ($\mathbf{AX}$). |
| **Displaying multi-digit results** | Using repeated division by 10 to convert binary results into printable ASCII digits. |