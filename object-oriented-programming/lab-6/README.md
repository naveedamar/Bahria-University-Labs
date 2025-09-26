# OOP Lab 06 – Sealed Classes, Final Keyword & Multi-Level Inheritance

## 📝 Tasks

### Task 1: Sealed Classes in a Banking System
- Create a sealed class `BankAccount` that only permits `SavingsAccount` and `CurrentAccount`.
- Make `SavingsAccount` **final** (cannot be extended).
- Make `CurrentAccount` **non-sealed**, allowing further inheritance.
- Create a `BusinessAccount` subclass that extends `CurrentAccount`.
- Demonstrate object creation for `SavingsAccount` and `BusinessAccount` in `main`.

---

### Task 2: Using the `final` Keyword in a Library System
- Create a `Library` class with a **final method** `getLibraryName()` returning `"City Library"`.
- Try to override `getLibraryName()` in `PublicLibrary` (should cause an error).
- Create a **final class** `DigitalLibrary` (cannot be extended).
- Attempt to extend `DigitalLibrary` in `OnlineLibrary` (should cause an error).
- Demonstrate a **final variable** (`MAX_BOOKS = 100`) that cannot be changed after initialization.

---

### Task 3: Multi-Level Inheritance in an Employee Management System
- Create a base class `Employee` with `name`, `salary`, and method `displayInfo()`.
- Create a subclass `Manager` extending `Employee`, adding `teamSize`.
- Create a subclass `SeniorManager` extending `Manager`, adding `bonus`.
- Create a `SeniorManager` object and call `displayInfo()` to show all inherited properties.

---

## ▶️ How to Run
Compile any task file:
```bash
    javac TaskX.java
