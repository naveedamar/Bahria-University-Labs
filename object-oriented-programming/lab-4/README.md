# OOP Lab 04 – Inheritance in Java

## 📘 Lecture Overview
Inheritance allows a new class (subclass) to inherit properties and behavior from an existing class (superclass).  
It promotes **code reusability**, **hierarchical relationships**, and **method overriding**.

### Key Concepts
1. Base Class (Superclass) & Derived Class (Subclass)
2. Using the `super` Keyword
3. Constructor Chaining
4. Method Overriding
5. Types of Inheritance
6. Access Modifiers and Inheritance

---

## 📝 Tasks

### Task 1: Single Inheritance
- Create a `Person` class with a `displayInfo()` method (prints name & age).
- Create a subclass `Student` with `studentID`.
- Create a `Student` object and call `displayInfo()`.

### Task 2: Constructor Chaining with `super()`
- Create a `Vehicle` class with a parameterized constructor that prints `"Vehicle Created"`.
- Create a subclass `Car` that extends `Vehicle` and calls `super()`.
- Create a `Car` object and observe constructor order.

### Task 3: Method Overriding
- Create a `Shape` class with `draw()` printing `"Drawing a shape"`.
- Create a subclass `Circle` that overrides `draw()` with `"Drawing a Circle"`.
- Create a `Circle` object and call `draw()`.

### Task 4: Multilevel Inheritance
- Create `Grandparent` class → `Parent` class → `Child` class.
- Add methods in each (`showGrandparent()`, `showParent()`, `showChild()`).
- Create a `Child` object and call all methods.

### Task 5: Using `super` to Call Superclass Methods
- Create `Animal` class with `makeSound()` printing `"Animal makes a sound"`.
- Create `Dog` subclass overriding `makeSound()` but also calling `super.makeSound()`.
- Create a `Dog` object and call `makeSound()`.

---

## ▶️ How to Run
Compile any task file:
```bash
    javac TaskX.java
