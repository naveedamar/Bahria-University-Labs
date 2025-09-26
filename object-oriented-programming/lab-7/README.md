# OOP Lab 07 – Hotel Room Booking System

## 🏨 Scenario
A hotel chain needs a system to manage room bookings. The system must handle different room types (Standard Rooms, Luxury Suites, VIP Suites), calculate booking costs, and demonstrate OOP concepts such as encapsulation, inheritance, polymorphism, constructor chaining, and aggregation.

---

## 📝 Tasks

### Task 1: Base Class and Encapsulation
- Create a base class `Room` with **private attributes**:
    - `roomId`, `roomType`, `pricePerNight`, `availability`
- Provide **getters and setters** for encapsulation.
- Add a **parameterized constructor** and a **default constructor** using **constructor chaining**.

---

### Task 2: Multi-Level Inheritance and Constructor Chaining
- Create subclasses of `Room`:
    - `StandardRoom` → adds `hasTV`.
    - `LuxurySuite` → adds `hasJacuzzi`.
    - `VIPLuxurySuite` → extends `LuxurySuite` and adds `personalButlerService`.
- Each subclass must call the **base constructor** using `super()`.
- Demonstrate **multi-level inheritance** with `VIPLuxurySuite`.

---

### Task 3: Polymorphism through Overriding and Overloading
- In `Room`, implement a method `calculateBookingCost(int nights)`.
- **Overload** it with a version that accepts a discount percentage.
- **Override** it in subclasses to add charges:
    - `LuxurySuite`: Add **luxury tax**.
    - `VIPLuxurySuite`: Add **premium services fee**.

---

### Task 4: Aggregation and Booking Management
- Create a `Booking` class that **aggregates a Room object**.
- Store booking details:
    - Check-in date
    - Number of nights
    - Guest information
    - Final booking cost (calculated using `calculateBookingCost`)

---

## ▶️ How to Run
Compile the program:
```bash
    javac Main.java
