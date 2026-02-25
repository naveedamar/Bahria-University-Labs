# 🏛️ CSC 327: Computer Architecture - Lab 3

## 🎯 Objective
To understand control flow, branching (`beq`, `bne`), and decision-making in MIPS.

## 🛠️ Theory & Commands
- `beq` / `bne`: Branch if equal / not equal.
- `bgtz` / `bltz`: Branch if > 0 / < 0.
- `j`: Unconditional jump.

## 📝 Tasks Completed
- **Task 1:** Checked if a number is positive using `bgtz`.
- **Task 2:** Checked for Even/Odd using `div` and `mfhi`.
- **Task 3:** Compared two integers to find the greater one.

## 🧠 Quiz Answers
- `j` is for unconditional branching.
- `beq ... $zero` checks if a register is **zero**.
- PC increments by 4 normally, not just on branches.
- `mfhi` retrieves the remainder to check Even (0) vs Odd (1).

## 🚀 Open-Ended Task: Largest of Three
Implemented logic to compare three integers using sequential conditional branches to isolate and print the largest value.

## 🏁 Conclusion
Learned to control program flow dynamically using jumps and conditional branches to implement `if-else` logic.