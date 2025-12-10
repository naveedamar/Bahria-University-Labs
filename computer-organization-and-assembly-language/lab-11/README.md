# 🖥️ COAAL – Lab 11

Lab 11 focused on **Rotate Instructions (ROL & ROR)** in **8086 Assembly Language**, extending the concepts from shift operations to circular bit manipulation. Rotation instructions are vital when the shifted-out bits must be preserved and reused, especially in low-level graphics, encryption, device control, and data scrambling.

---

> **Note:** Unlike SHL/SHR, rotate instructions **do not discard bits**—they wrap them around. This makes them essential for cyclic operations and reversible transformations.

---

## 🎯 Objectives

By the end of this lab, students were expected to:

* Understand and apply **ROL (Rotate Left)** and **ROR (Rotate Right)** instructions.
* Scramble bit patterns using rotation operations.
* Observe and interpret the **Carry Flag (CF)** behavior during rotations.
* Implement iterative bit-movement patterns using loops.
* Display bit representations to verify correct rotational behavior.

---

## 📝 Exercises

### **Exercise 1**

Write a program that takes the pattern `11000011b` and generates two scrambled versions:

1. **Scramble 1:** Move the two MSBs to the LSB positions using **ROL**.
2. **Scramble 2:** Move the two LSBs to the MSB positions using **ROR**.
3. Display the **original** byte and both **scrambled** results in binary to verify the transformations.

---

### **Exercise 2**

Demonstrate how **ROL** affects both the **data bits** and the **Carry Flag (CF)**.

Requirements:

* Initialize a byte with: `10000001b`.
* Rotate left by **1** using `ROL`.
* Create a procedure named **display_binary_cf** that:

  * Prints the 8-bit binary value in AL.
  * Prints the status of the Carry Flag (`CF = 0` or `CF = 1`) immediately after the number.

The output must clearly show both:

* Before rotation
* After rotation

---

### **Exercise 3**

Write a program to demonstrate repeated rotations using **ROL**:

* Initialize a byte with: `11110000b` (`F0h`).
* Rotate this byte **4 times**, each time by 1 bit.
* After each rotation, display:

  * The current **iteration number**.
  * The **new binary value** of the byte.

This exercise reinforces the cyclic nature of rotations.

---

### **Exercise 4**

Use **ROR** to create a "moving bit" pattern. Start with the MSB set (`10000000b`) and rotate the 1-bit to the right step-by-step.

The program must produce exactly:

```
Pattern 1: 10000000
Pattern 2: 01000000
Pattern 3: 00100000
Pattern 4: 00010000
Pattern 5: 00001000
Pattern 6: 00000100
Pattern 7: 00000010
Pattern 8: 00000001
```

This exercise demonstrates controlled cyclic motion of a single bit using rotation.
