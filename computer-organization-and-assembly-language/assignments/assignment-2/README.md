# 🧮 COAAL - Assignment 2
### Booth’s Algorithm for Signed Binary Multiplication  

---

## 🎯 Objective  
To understand and implement **Booth’s Algorithm** in Assembly Language for multiplying **signed binary numbers** using arithmetic shifts and bit-pair analysis.  

---

## 🧠 Conceptual Explanation  

Booth’s Algorithm is an efficient method for performing **signed multiplication** in binary. It works by examining consecutive **bit pairs** of the multiplier to determine whether to **add**, **subtract**, or **do nothing** with the multiplicand, followed by an **arithmetic right shift**.  

The key rules are:  
- If the pair is `01` → **Add** multiplicand to the accumulator  
- If the pair is `10` → **Subtract** multiplicand from the accumulator  
- If the pair is `00` or `11` → **No operation**  

After each operation, the combined **accumulator and multiplier** are **arithmetically right-shifted**, preserving the sign bit. This ensures that **positive and negative numbers** are correctly handled in two’s complement representation.  

Booth’s Algorithm therefore optimizes multiplication by reducing unnecessary additions/subtractions and allows a uniform approach for both positive and negative operands.  

---

## ⚙️ Task Description  

1. Declare variables for the **multiplicand**, **multiplier**, and **result** in the data segment.  
2. Implement Booth’s Algorithm using **bitwise operations**, **arithmetic shifts**, and **conditional logic**.  
3. Test the implementation for both **positive and negative** signed 4-bit numbers (e.g., `6 × -3`, `-4 × 2`, `-5 × -2`, `3 × 3`).  
4. Convert the final binary output into its **decimal equivalent** and display it.  

---

## 📚 Key Concepts  

- Signed Binary Representation (Two’s Complement)  
- Arithmetic Right Shift (`SAR`)  
- Conditional Jump Instructions (`JZ`, `JC`, `JNZ`)  
- Booth’s Bit-Pair Examination Logic  
- Handling of Positive and Negative Operands  

---

## 🧩 Expected Output Examples  

| Multiplicand | Multiplier | Result |
|---------------|-------------|---------|
| 6             | -3          | -18     |
| -4            | 2           | -8      |
| -5            | -2          | 10      |
| 3             | 3           | 9       |

---

## 🧾 Outcome  

By completing this lab, students will:  
- Understand how Booth’s Algorithm simplifies signed multiplication.  
- Gain practical experience implementing arithmetic logic in 8086 Assembly.  
- Learn how two’s complement and arithmetic shifts affect binary operations.  
