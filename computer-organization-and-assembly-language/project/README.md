# 🚗 Parking Management System (8086 Assembly)

This project aims to build a simple **Parking Management System** using 8086 assembly language. It allows users to record vehicle entries, calculate parking fees, and maintain basic parking slot information. The project demonstrates the practical application of low-level programming concepts, including memory access, conditional processing, data representation, and input/output handling in assembly.

---

## 🎯 Project Scope & Abstract

The project focuses on developing a basic system where a user can enter vehicle details, assign parking slots, calculate charges based on parking duration, and display summary reports.

**Key Highlights:**
*   **Low-Level Programming:** Demonstrates real-life application of assembly language.
*   **Data Handling:** Uses arrays and simple I/O via DOS interrupts.
*   **Constraints:** Limited to small-scale data handling and hardware-style constraints.
*   **Core Concepts:** Highlights the practical usage of arrays, loops, and arithmetic instructions.

---

## 🛠️ Project Functionalities

### 1. Vehicle Entry Input
**Scenario:** A vehicle arrives at the parking lot.
**Functionality:**
*   The system prompts the user to enter a vehicle identifier (e.g., vehicle number or type like Car, Bike, Rikshaw).
*   Input is taken as a single-digit or multi-character string using DOS interrupts.
*   Information is stored temporarily in memory for processing.

### 2. Slot Assignment
**Scenario:** Finding a place to park.
**Functionality:**
*   The system maintains a small array representing parking slots (e.g., 5-10 slots).
*   It searches for the first available (empty) slot and assigns it to the vehicle.
*   If all slots are full, the user is notified.
*   Slot assignment and status updates are managed using simple array operations.

### 3. Entry & Exit Time Recording
**Scenario:** Tracking how long a vehicle stays.
**Functionality:**
*   Entry and exit times are taken as simplified numeric values (0–9 or 0–23).
*   The program stores the entry time when a vehicle is parked.
*   It later prompts the user for the exit time when the vehicle leaves.
*   Time difference is calculated using basic arithmetic instructions.

### 4. Fee Calculation
**Scenario:** Determining the cost of parking.
**Functionality:**
*   Based on the duration (Exit Time – Entry Time), the system computes the parking charge.
*   A simple flat rate or per-hour rate (e.g., 10 units per hour) is applied.
*   The fee is added to the total earnings.
*   Calculations use 8086 arithmetic instructions (`ADD`, `SUB`, `MUL`).

### 5. Parking Summary Display
**Scenario:** Viewing the current status of the parking lot.
**Functionality:**
*   Displays a summary including:
    *   Number of occupied slots.
    *   Number of available slots.
    *   Total earnings collected so far.
*   Information is printed using DOS interrupt output services.

### 6. Safe Exit
**Scenario:** Closing the application.
**Functionality:**
*   A clean exit routine releases control back to DOS using interrupt `INT 21H` with function `4CH`.
*   Ensures proper termination without corrupting registers or memory.

---

## 👥 Module Distribution

### Naveed
**Module 1 – User Input & Validation**
*   Input vehicle number/type.
*   Input entry/exit time.
*   Basic error handling.

**Module 2 – Slot Assignment Logic**
*   Maintain array of available slots.
*   Mark slot as occupied/free.
*   Search for free slot.

### Yamaan Altaf
**Module 3 – Fee Calculation**
*   Compute parking charges based on duration.
*   Store earnings.

**Module 4 – Output & Reporting**
*   Display parking status.
*   Print summary.
*   Generate simple report on console.
