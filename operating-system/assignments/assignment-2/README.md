# OS Assignment 02: Multi-Process Account Management System

This assignment demonstrates Shared Memory and Process Synchronization using Semaphores in a Linux environment.

## Problem Statement
Develop a system where multiple **Teller Processes** concurrently access and update a shared bank account balance.

### System Workflow
1. **Parent Process:**
   * Allocates Shared Memory for the `balance` variable.
   * Initializes the balance to **Rs. 1000**.
   * Initializes a **Semaphore** to manage access to the Critical Section.

2. **Teller Processes (3 Children):**
   * Each teller performs **100 deposits** of **Rs. 10**.
   * Uses `sem_wait()` and `sem_post()` to ensure Mutual Exclusion.
   * Updates the shared balance safely.

3. **Final Result:**
   * Parent waits for all tellers to finish.
   * Displays the final balance (Expected: **Rs. 4000**).

---

## Evaluation Logic
* **Initial Balance:** 1000
* **Transactions:** 3 Tellers × 100 Deposits × Rs. 10 = 3000
* **Final Balance:** 1000 + 3000 = 4000
* **Critical Section Protection:** Semaphores prevent data corruption.

---

## Requirements
* **Language:** C
* **Environment:** Ubuntu (Linux)
* **System Calls:** `shmget()`, `shmat()`, `sem_open()`, `fork()`, `wait()`

## Compilation and Execution
To compile and run the program in the Ubuntu terminal:

* Navigate to assignment folder
    ```bash
    cd assignment-2
    ```

* Compile the C file (include -pthread for semaphores)
    ```bash
    gcc account-management-system.c -o account-management -pthread
    ```

* Run the program
    ```bash
    ./account-management
    ```