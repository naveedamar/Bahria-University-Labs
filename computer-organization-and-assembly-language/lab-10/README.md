# 🖥️ COAAL – Lab 10

Lab 10 focused on **Shift and Rotate Instructions** in **8086 Assembly Language**. This session explored using these instructions as highly efficient alternatives to standard multiplication and division, especially when dealing with powers of two.

-----

> **Note:** Shift instructions are critical for performance, as multiplying or dividing by powers of two ($2^N$) using shifting is significantly faster than general arithmetic instructions.

-----

## 🎯 Objectives

By the end of this lab, students were expected to:

  * Understand and apply **Shift Left (SHL)** for fast multiplication by powers of two.
  * Understand and apply **Shift Right (SHR/SAR)** for fast division by powers of two.
  * Correctly use the immediate count (1) or the **CL** register for specifying the number of shifts.
  * Write concise assembly code to perform arithmetic operations using bit manipulation.

-----

## 📝 Exercises

### **Exercise 1**

```assembly
MOV BL, 00001111b
MOV CL, 4
SHL BL, CL
```

After performing 4 times shift left operation, show the content of BL register in binary format only.

**Result:** `11110000b` (Decimal: 240)

-----

### **Exercise 2**

Write two instructions to divide **BX** by 4 using shift instructions.

**Answer:**

```assembly
SHR BX, 1   ; Divide by 2
SHR BX, 1   ; Divide by 2 again (Total division by 4)
```

*(Alternatively: `MOV CL, 2` and `SHR BX, CL`)*

-----

### **Exercise 3**

Write a program to multiply 10d by 4d using the appropriate Shift instruction. Also show the final content of the resultant register on EMU8086.

**Answer:**

```assembly
org 100h
MOV AL, 10d ; Load 10 into AL (0Ah)
MOV CL, 2   ; Shift count 2 (for multiplication by 2^2 = 4)
SHL AL, CL  ; AL = 10d * 4d = 40d
RET
```

**Final content of AL:** `28h` (Decimal: 40)

-----

### **Exercise 4**

To multiply a number by 16, how many times must it be shifted to the left?

**Answer:** 4 times (since $2^4 = 16$).

-----

## 📂 Key Concepts

| Concept                          | Instruction | Application                                                  |
| :------------------------------- | :---------- | :----------------------------------------------------------- |
| **Logical Shift Left** | `SHL`       | Fast **Multiplication** by powers of two.                    |
| **Logical Shift Right** | `SHR`       | Fast **Unsigned Division** by powers of two.                 |
| **Arithmetic Shift Right** | `SAR`       | Fast **Signed Division** by powers of two (preserves sign).  |
| **Rotate Instructions** | `ROL/ROR`   | Bit manipulation where bits shifted off one end wrap around. |

-----

This lab demonstrated essential techniques for optimized arithmetic processing, proving that bit manipulation is key to writing high-performance assembly code.