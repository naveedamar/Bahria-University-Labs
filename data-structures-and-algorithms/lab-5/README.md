# 🧮 DSA Lab 05 – Stack Implementation

---

## 🎯 Objectives

By completing this lab, students will be able to:

* Understand and implement the **concept of stack**.
* Apply stack operations (`push`, `pop`, `display`) in real-world scenarios.
* Use stacks to solve problems in utilities, calculators, editing software, and games.

---

## 📝 Exercises

### 1. Utility Bill Stack Organizer

Implement a stack to manage **household utility bills** (capacity = 10). Functions required:

* `addBill()` – Add a bill to the stack (if not full).
* `removeBill()` – Pay (remove) the last bill (if not empty).
* `displayBills()` – Display all bills currently in the stack.

**Test Procedure:**

* Add 11 bills (Electricity → Loan Repayment).
* Display stack.
* Remove one bill.
* Display updated stack.

---

### 2. Postfix Expression Evaluator

Implement a **calculator app** that evaluates mathematical expressions in **postfix notation** using a stack.

* Push numbers onto the stack.
* On operator (`+`, `-`, `*`, `/`), pop last two numbers, evaluate, and push result.
* Handle errors such as **divide by zero** and **insufficient operands**.

---

### 3. Image Editing (Undo Feature)

Design a stack-based **image editing program** with max 10 edits.

* Store edits as stack operations:

  1. Brightness adjustment
  2. Cropping
  3. Applying filters (grayscale, sepia)
  4. Rotation
* Implement an **undo feature** to revert to previous edit states.

---

### 4. Fruit Stack Frenzy

Create a **stack-based fruit game** with 4 containers (capacity = 3 fruits each).

* Fruits: Apple, Kiwi, Orange.
* Initially, fruits are randomly placed in 3 jars; 4th jar is empty.
* Goal: Arrange so that 3 jars contain only **one fruit type each**.
* Rules: Only fruits of the same type can be stacked on top of each other.

---

## 📂 Key Concepts

* **Stack operations** (`push`, `pop`, `display`)
* Stack applications in:

  * **Bill management**
  * **Expression evaluation**
  * **Undo operations**
  * **Puzzle/game design**
