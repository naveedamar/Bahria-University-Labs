# 🖥️ COAAL – Lab 13: Stack Operations

This lab focuses on mastering the 8086 stack, a fundamental component for managing data, controlling program flow, and performing calculations. Each exercise provides a real-world scenario where the stack is not just a tool but a requirement, forcing you to think in a Last-In, First-Out (LIFO) manner.

---

## 🎯 Objectives

By the end of this lab, students will be able to:

*   **Manipulate the stack** using `PUSH` and `POP` to store and retrieve data.
*   **Implement stack-based algorithms** for common tasks like swapping values and reversing data.
*   **Perform arithmetic calculations** using the stack as temporary storage, avoiding register overuse.
*   **Simulate real-world LIFO structures**, such as a web browser's history, using the stack segment.
*   **Debug stack operations** by observing the stack pointer (`SP`) and memory in EMU8086.

---

## 📝 Exercises

### Exercise 1 — Register Swap via Stack

**Scenario:** An old 8086-based controller's stack functionality needs to be verified. A simple swap test is required to confirm that `PUSH` and `POP` are working correctly.

**Problem statement:**
Write an 8086 program that:
1.  Loads `AX` with `100` and `BX` with `200`.
2.  Swaps their values using **only stack operations** (`PUSH` and `POP`).
3.  Displays the register values before and after the swap to verify the result.
4.  **Constraint:** Do not use `XCHG` or any extra registers for the swap.

**Expected output:**
```
Before Swap: AX = 100, BX = 200
After Swap:  AX = 200, BX = 100
```

---

### Exercise 2 — Reverse String with Stack

**Scenario:** You are programming a mini-game for an 8086 console that has a "Reverse Input" feature. This feature relies exclusively on the stack to process and reverse character sequences.

**Problem statement:**
Write an 8086 routine that:
1.  Takes the hardcoded input string `"ABC"`.
2.  Pushes each character onto the stack.
3.  Pops each character back off the stack to produce a reversed string.
4.  Displays the reversed string on the screen.

**Expected output:**
```
Reversed String: CBA
```

---

### Exercise 3 — Stack-Based Arithmetic

**Scenario:** A legacy 8086 billing device performs all calculations using the stack to ensure intermediate values are not held in general-purpose registers for security reasons.

**Problem statement:**
Write an 8086 program that:
1.  Computes the expression `(15 + 25) * 2`.
2.  Performs all intermediate steps using **only stack instructions** (`PUSH` and `POP`) for storing and retrieving values.
3.  Displays the final calculated result in decimal format.

**Expected output:**
```
Result = 80
```

---

### Exercise 4 — Browser History Simulation

**Scenario:** You are developing the "History" module for a simple text-based browser. The "Back" button must function using the Last-In, First-Out (LIFO) principle, which is a perfect use case for the stack.

**Problem statement:**
Write an 8086 program that simulates a user's browsing session:
1.  **Browsing Phase:** The user visits three pages with IDs `101`, `102`, and `103` in that order. Use `PUSH` to store these IDs on the stack.
2.  **Back Button Phase:** The user clicks the "Back" button three times. Use `POP` to retrieve the Page IDs from the stack.
3.  Display messages to show the order of visits and the order of retrieval from the history.

**Expected output:**
```
Visiting Page: 101
Visiting Page: 102
Visiting Page: 103

Navigating Back to: 103
Navigating Back to: 102
Navigating Back to: 101
```
