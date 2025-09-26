# OOP Lab 10 – Interfaces in Java

## 📘 Overview
An **interface** in Java defines a contract.
- It contains **method signatures** but no implementations.
- Classes that implement an interface **must provide implementations** for all methods.

### 🔹 Why Use Interfaces?
- **Abstraction** → Hides implementation details.
- **Multiple Inheritance** → A class can implement multiple interfaces.
- **Loose Coupling** → Improves flexibility, testability, and reusability.

---

## 📝 Tasks

### Task 1: Interface for Printable Entities
1. Create an interface `IPrintable` with method `print()`.
2. Implement `IPrintable` in:
    - `Document` → prints "Printing Document..."
    - `Image` → prints "Printing Image..."
3. Demonstrate interface usage:
    - Create an array of `IPrintable` objects (with `Document` and `Image`).
    - Use a loop to call `print()` for each object.

---

### Task 2: Interface for Payment Processing
1. Create an interface `IPaymentProcessor` with method `processPayment(double amount)`.
2. Implement `IPaymentProcessor` in:
    - `CreditCard` → prints "Processing credit card payment of amount $X..."
    - `PayPal` → prints "Processing PayPal payment of amount $X..."
3. Demonstrate polymorphism:
    - Store objects (`CreditCard`, `PayPal`) in a list of `IPaymentProcessor`.
    - Loop through the list and call `processPayment()`.

---

### Task 3: Multiple Inheritance with Interfaces
1. Create interfaces:
    - `IEngine` → `startEngine()`, `stopEngine()`
    - `IVehicle` → `drive()`, `park()`
2. Create a `Car` class that implements both `IEngine` and `IVehicle`.
    - `startEngine()` → "The car engine is now running."
    - `stopEngine()` → "The car engine is now stopped."
    - `drive()` → "The car is driving."
    - `park()` → "The car is parked."
3. Demonstrate multiple inheritance:
    - Instantiate `Car` and call all methods.
    - Extend further with additional interfaces (e.g., `ISafetyFeatures`, `IMaintenance`) to show scalability.

---

## ▶️ How to Run
Compile all `.java` files:
```bash
    javac *.java
