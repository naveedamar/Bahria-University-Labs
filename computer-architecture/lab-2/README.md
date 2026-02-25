# 🏛️ CSC 327: Computer Architecture - Lab 2

## 🎯 Objective
To implement basic arithmetic operations (`add`, `sub`, `addi`) and manage registers in MIPS.

## 🛠️ Commands Learned
- `add $d, $s, $t` / `sub $d, $s, $t`: Register arithmetic.
- `addi $t, $s, imm`: Add constant.
- `syscall`: Input (`$v0=5`) and Output (`$v0=1`).

## 📝 Tasks Completed
- **Task 1 & 2:** Added and subtracted two user-input integers.
- **Task 3:** Added a constant (10) to user input.

## 🧠 Quiz Answers
- `addi` adds an immediate constant.
- Results are stored in the **destination** register.
- `addu` does **not** generate overflow exceptions.
- `$v0` sets the call type; `$a0` holds the argument.

## 🚀 Open-Ended Task: Z = (X+Y) - (X-Y)
Calculated a dynamic expression using user inputs.
- Used `$t0-$t3` for inputs and intermediate steps.
- Used `add`, `sub`, and `move` to compute and print the final result `Z`.

## 🏁 Conclusion
Reinforced core arithmetic instructions, register management, and handling user I/O in MIPS.