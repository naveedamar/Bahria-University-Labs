# OOP Lab 09 – Abstraction in Java (Abstract Classes)

## 📘 Overview
This lab focuses on **abstraction** in Java using **abstract classes**.  
An **abstract class** cannot be instantiated directly. It can have both:
- **Abstract methods** (no implementation, must be implemented in subclasses)
- **Concrete methods** (with implementation, can be inherited by subclasses)

This lab demonstrates **inheritance**, **polymorphism**, and **abstraction** through two tasks.

---

## 📝 Tasks

### Task 1: Abstract Class for Geometric Shapes
1. Create an abstract class `Shape` with:
    - Abstract method `calculateArea()`
    - Non-abstract method `displayDetails()`
    - Abstract property `name`
2. Create derived classes:
    - `Circle` (constructor takes `radius`)
    - `Rectangle` (constructor takes `width`, `height`)
    - `Triangle` (constructor takes `base`, `height`)
3. Demonstrate **polymorphism**:
    - Store different shapes in an array of `Shape`
    - Loop through the array and call `calculateArea()` and `displayDetails()`

---

### Task 2: Abstract Class for Vehicle Management
1. Create an abstract class `Vehicle` with:
    - Abstract methods `startEngine()` and `stopEngine()`
    - Non-abstract method `displayVehicleType()`
    - Abstract property `vehicleType`
2. Create derived classes:
    - `Car`
    - `Motorcycle`
    - `Truck`
3. Demonstrate **polymorphism**:
    - Store different vehicles in a list of `Vehicle`
    - Loop through the list and call `startEngine()`, `stopEngine()`, and `displayVehicleType()`

---

## ▶️ How to Run
Compile all `.java` files:
```bash
    javac *.java
