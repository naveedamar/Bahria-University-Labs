# 📝 Mid Exam – Object Oriented Programming (Java)

## Scenario: Vehicle Rental Management System
A vehicle rental company needs a software system to manage **different types of vehicles (Car, Truck, HeavyTruck)**, their **rental costs**, and **contracts** with customers.  
The system must demonstrate **OOP concepts** like Encapsulation, Inheritance, Polymorphism, Constructor Chaining, Access Modifiers, and Multi-Level Inheritance.

---

## Question 1 [CLO1 – CLO4] 

### Task 1: Base Class and Encapsulation (CLO1)
- Create a base class `Vehicle` with private attributes:
    - `vehicleId`
    - `brand`
    - `model`
    - `rentalRate` (cost per day)
    - `isAvailable` (boolean)
- Requirements:
    - Provide **getter/setter methods** (Encapsulation).
    - Add **parameterized constructor** for initialization.
    - Implement `displayDetails()` to print vehicle info.
    - Validate:
        - `rentalRate` must not be negative.
        - `vehicleId` must follow format like `"V-1001"`.

---

### Task 2: Multi-Level Inheritance & Constructor Chaining (CLO2)
- Derived classes:
    - `Car` → adds `numberOfDoors`.
    - `Truck` → adds `loadCapacity`.
    - `HeavyTruck` → extends `Truck`, adds `maxTonnage`.
- Requirements:
    - Use **constructor chaining (`super()`)** in each subclass.
    - Override `displayDetails()` for each.
    - Truck rule: If `loadCapacity > 5000kg`, add service fee.
    - HeavyTruck rule: If `maxTonnage > 10 tons`, apply licensing restrictions.

---

### Task 3: Polymorphism (Overriding & Overloading) (CLO3)
- In `Vehicle`:
    - `calculateRentalCost(int days)` → rentalRate × days.
        - If days > 7 → apply 10% discount.
    - **Overload** → `calculateRentalCost(int days, double discountPercentage)`.
- Override in subclasses:
    - **Car** → Apply luxury tax (brands: BMW, Audi).
    - **Truck** → Add service charge if loadCapacity > 5000.
    - **HeavyTruck** → Add permit fee if maxTonnage > 10 tons.

---

### Task 4: Multi-Level Inheritance & Object Usage (CLO4)
- Create class `RentalContract`:
    - Aggregates a `Vehicle`.
    - Stores: customer name, contactNumber, rental period, total rental cost.
    - Method `printContractDetails()`.
- Extend into `CorporateRentalContract`:
    - Adds **companyName**.
    - Applies **15% corporate discount**.

---

### Task 5: Final Usage
In `main()`:
1. Create objects of `Car`, `Truck`, `HeavyTruck`.
2. Call `displayDetails()` on each.
3. Calculate rental cost using **both overloaded and overridden methods**.
4. Create `RentalContract` and `CorporateRentalContract` objects.
5. Call `printContractDetails()` for both.
6. Ensure all methods/attributes are demonstrated.

---

## ✅ Concepts Tested
- Encapsulation (getters/setters, private fields)
- Inheritance (Car, Truck, HeavyTruck hierarchy)
- Constructor Chaining (`super()`)
- Polymorphism (method overriding & overloading)
- Access Modifiers (proper visibility)
- Multi-Level Inheritance (Truck → HeavyTruck)
- Aggregation (Vehicle inside RentalContract)

---
