# OS Lab 07: System Commands and Process Creation

This lab focuses on interacting with the Linux kernel through Python to manage system processes and execute shell commands.

## Problem Statements

### Exercise 1: Linux Command Invocation
Using the `subprocess` module to bridge Python with the Ubuntu shell.
* **Task 1:** Execute the `ls` command to list directory contents.
* **Task 2:** Utilize the `w` command to display active processes for all logged-in users.

### Exercise 2: System Utilities Functionality
Implementation of modular functions to handle system metadata and file operations.
* **System Info:** Displaying OS name, time, and hardware architecture.
* **Encryption:** Securing file data using symmetric encryption keys.
* **File Stats:** Counting lines, words, and characters (mimicking the `wc` command).

### Exercise 3: Process Creation
Understanding the lifecycle of processes through system calls.
* **Child Process:** Using `os.fork()` to spawn a new process from a parent.
* **Parent-Child Relationship:** Identifying processes using PIDs and PPIDs and managing execution flow.

---

## Requirements
* **Environment:** Ubuntu (Linux)
* **Language:** Python 3.x
* **Modules:** `os`, `subprocess`, `platform`, `cryptography`