# 🖥️ COAAL – Lab 9

Lab 9 focused on **bitwise operations** in **8086 Assembly Language**. This session was **theoretical**, involving conceptual understanding and manual computation of results rather than writing full executable programs.

---

> **Note:** Lab 9 was **entirely theoretical**. Students solved bitwise operation problems manually and wrote short code snippets only where required.

---

## 🎯 Objectives

By the end of this lab, students were expected to:

* Understand and apply **bitwise operations** (AND, OR, XOR) on 8-bit and 16-bit operands.
* Analyze binary patterns and predict the resulting output after logical operations.
* Use bitmasks to **clear** or **set** specific bits in a register.
* Modify simple assembly instructions involving 16-bit registers.

---

## 📝 Exercises

### **Exercise 1**

Apply bitwise operations on given operands and compute the results:

1. `MOV AL, 01101111b` → `AND AL, 00101101b` → **Result:** `00101101b`
2. `MOV AL, 6Dh` → `AND AL, 4Ah` → **Result:** `01001000b`
3. `MOV AL, 00001111b` → `OR AL, 61h` → **Result:** `01101111b`
4. `MOV AL, 94h` → `XOR AL, 37h` → **Result:** `10100011b`

---

### **Exercise 2**

Write a single 16-bit instruction that clears **AH** while keeping **AL** unchanged.

**Answer:** `AND AX, 00FFh`

---

### **Exercise 3**

Write a single 16-bit instruction that sets all bits of **AH** without affecting **AL**.

**Answer:** `OR AX, FF00h`

---

### **Exercise 4**

Modify a program to perform an **AND** operation between two 16-bit registers.

**Answer:**

```
org 100h
MOV AX, 6A35h
MOV BX, 3F8Ch
AND AX, BX
RET
```

---

### **Exercise 5**

Modify a program to perform an **OR** operation between two 16-bit registers.

**Answer:**

```
org 100h
MOV AX, 4A20h
MOV BX, 1180h
OR AX, BX
RET
```

---

## 📂 Key Concepts

| Concept                          | Description                                                  |
| :------------------------------- | :----------------------------------------------------------- |
| **Bitwise AND**                  | Used for masking and clearing bits.                          |
| **Bitwise OR**                   | Used for setting specific bits.                              |
| **Bitwise XOR**                  | Used for bit toggling.                                       |
| **Binary pattern analysis**      | Understanding how register contents change after operations. |
| **16-bit register manipulation** | Applying operations on AX, AH, and AL effectively.           |

---

This lab reinforced logical understanding of bitwise operations, preparing students for more advanced manipulation of data in assembly language.
