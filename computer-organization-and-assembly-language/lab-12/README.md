# 🖥️ COAAL – Lab 12

This lab covers practical assembly routines for array processing, bitwise testing, CPU flag observation, and simple timing/loop control. Each exercise combines a real-world scenario with strict debugging and code requirements so you demonstrate both correct functionality and diagnostic skills in the EMU8086 environment.

---

## 🎯 Objectives

By the end of this lab, students will be able to:

* Traverse and process arrays using indexed addressing (`SI`) and loop counters (`CX`).
* Convert binary results to printable decimal output and preserve remainders across DOS calls.
* Use bitwise operations to test parity (even/odd) and implement clean procedure calls.
* Observe and interpret CPU status flags (CF, OF) after arithmetic operations.
* Implement and debug simple countdown timers using loop control and debugging tools in EMU8086.

---

## 📝 Exercises

### Exercise 1 — Data Processing System (Array Sum)

**Scenario:** DataFlow Systems needs firmware to compute the total of 10 hourly sensor readings.

**Problem statement:**
Write an 8086 program that sums 10 numbers stored in an array:

```
[5, 8, 3, 9, 2, 7, 1, 6, 4, 0]
```

Display the result in decimal as:

```
Sum: 45
```

**Debugging requirements (what you must verify while testing):**

1. Loop executes exactly 10 times (`CX = 10` initially).
2. Final sum equals 45.
3. Decimal conversion separates digits correctly (tens = 4, ones = 5).
4. Remainder/pushed digits must be preserved across any `INT 21h` calls (save registers/stack as needed).

**Code requirements (must be satisfied in your submission):**

* Use `.MODEL SMALL`, `.DATA`, `.CODE`.
* Traverse array using `LEA SI, array` and indexed memory access `[SI]`.
* Use `CX` as loop counter for 10 iterations.
* Store final result in a `DW` variable.
* Convert the word result into two decimal digits (divide by 10, preserve remainder) and print as: `Sum: 45`.
* Restore registers before DOS calls where necessary.

**Expected output:** `Sum: 45`

---

### Exercise 2 — Even / Odd Detector

**Scenario:** MicroLogic Systems requires a diagnostic routine to select calibration mode based on parity.

**Problem statement:**
Write an 8086 program that takes the number `7`, displays it, determines even/odd via bitwise test, and displays either:

```
7 is Odd
```

or

```
7 is Even
```

**Debugging requirements:**

1. Verify ASCII conversion of `7` → `'7'`.
2. Confirm `AND AL, 1` yields `1` for odd (7) and sets Zero Flag appropriately.
3. Monitor Zero Flag after the `AND` instruction.
4. Confirm correct procedure call and return flow.
5. Ensure correct string displayed based on parity test.

**Code requirements:**

* Use `.MODEL SMALL`, `.DATA`, `.CODE`.
* Main procedure displays the number and calls `check_even_odd`.
* Implement `check_even_odd` that:

  * Tests parity with `AND AL, 1`.
  * Uses `JZ` (jump if zero) for even path; otherwise odd.
* Print either `" is Even"` or `" is Odd"` after the number.
* Include short comments explaining flag usage and procedure flow (comment lines allowed here for lab report).

**Expected behaviour:** For input `7`, program prints:

```
7 is Odd
```

---

### Exercise 3 — CPU Flag Tester (Carry vs Overflow)

**Scenario:** ChipTest Technologies needs a demo to teach difference between unsigned carry and signed overflow.

**Problem statement:**
Add two 8-bit numbers `200` and `100` (defined in `.DATA`) and report:

* The raw 8-bit result in AL (300 mod 256 = 44).
* Carry Flag status (should be `1` because unsigned 300 > 255).
* Overflow Flag status (should be `0` for these signed operands in this interpretation).

**Debugging requirements:**

1. Confirm AL holds 44 after addition (300 − 256).
2. Confirm `CF = 1` (unsigned overflow) — test with `JC`.
3. Confirm `OF = 0` — test with `JO`.
4. Verify conditional jumps (`jc`, `jo`) work properly and appropriate messages are printed.
5. Validate displayed messages reflect flag values correctly.

**Code requirements:**

* Use `.MODEL SMALL`, `.DATA`, `.CODE`.
* Define `num1 DB 200`, `num2 DB 100`.
* Perform `ADD AL, num2` (after loading AL with num1) to set flags.
* Use `JC` and `JNC` (or similar) to branch on Carry, and `JO`/`JNO` for Overflow.
* Display:

  ```
  Result (AL) = 44
  Carry Flag: 1
  Overflow Flag: 0
  ```

---

### Exercise 4 — Space Invaders Timer (Countdown Debugging)

**Scenario:** Game timer in Space Invaders must countdown correctly before game start.

**Problem statement:**
Fix and produce a working countdown program that prints:

```
Game starting in: 
3... 2... 1... 
GO!
```

(Each numbered line shows three dots after the digit; `GO!` appears on the next line.)

**Debugging requirements (during EMU8086 testing):**

1. Use breakpoints to inspect the loop and display routine.
2. Single-step through loop iterations and monitor `CL` (counter), `DL` (char to print) and flags after `DEC`/`LOOP`.
3. Verify memory locations for string/variables.
4. Confirm the loop executes the correct number of times and that printing uses correct CR/LF sequences.
5. Ensure program exits cleanly (`INT 21h` AH=4Ch).

**Code requirements:**

* Use `.MODEL SMALL`, `.DATA`, `.CODE`.
* Print header: `Game starting in: ` (then newline).
* Print `3...` then a space, `2...` space, `1...` newline, then `GO!` on a new line.
* Use `CX`/`CL` appropriately for counting and `INT 21h` services for output.
* Program exits with `INT 21h` AH=4Ch.

**Expected output:**

```
Game starting in: 
3... 2... 1... 
GO!
```

---

## 📂 Key Concepts (covered in Lab 12)

| Concept                             | Description                                                            |
| :---------------------------------- | :--------------------------------------------------------------------- |
| Array traversal                     | Using `LEA SI, array` and `LOOP`/`CX` to iterate fixed-size arrays.    |
| ASCII conversion                    | `SUB AL, '0'` and `ADD AL, '0'` for I/O ⇄ numeric conversions.         |
| Preserve registers across `INT 21h` | Save/restore registers on stack when needed.                           |
| Bitwise parity test                 | `AND AL, 1` and `JZ` to determine even/odd.                            |
| CPU flags                           | Observe `CF` (carry) and `OF` (overflow) after arithmetic.             |
| Decimal conversion                  | Repeated `DIV 10` and pushing remainders to print multi-digit numbers. |
| Debugging with EMU8086              | Breakpoints, single-step, register/memory watch to validate flow.      |
| Clean exit                          | `INT 21h` with `AH = 4Ch` to return control to DOS.                    |

---

## Submission checklist

* Include well-commented source files for each exercise (`.asm`) and a short test log showing the checks in the debugging requirements.
* Each program must assemble and run in **emu8086**.
* Provide a short `.md` or `.docx` summary showing outputs/screenshots and where you validated loop counts and flags.
