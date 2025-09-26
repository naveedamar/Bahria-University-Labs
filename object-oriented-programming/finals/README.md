# 🍽️ Food Ordering System – OOP Lab Final

## 📌 Objective
The objective of this task is to design a Food Ordering System for a restaurant using **Object-Oriented Programming (OOP) concepts in Java**.  
The system should handle different cuisines (Asian, Italian, Mexican) and their specific dishes, while maintaining **abstraction, encapsulation, inheritance, and polymorphism**.

---

## 🛠️ Object-Oriented Concepts Implemented
- **Abstraction** → Base class/blueprint for meals.
- **Inheritance** → Asian, Italian, and Mexican meals extend the base meal class.
- **Polymorphism** → Different dishes (Pasta, Pizza, Sushi, Stir Fry, Burrito, Taco) show dynamic behavior when selected.
- **Encapsulation** → Attributes like size, toppings, drinks, and price are kept private and accessed via secure methods.

---

## 🖥️ Implementation Summary
- A **base class** defines common food item properties and methods.
- **Asian meals** require number of portions (special rule).
- **Italian meals** allow Pasta or Pizza selection.
- **Mexican meals** allow Burrito or Taco with customizable fillings.
- A **common structure** (array/list of meals) allows handling different cuisines without knowing exact details.
- Orders are fully initialized when created.

---

## 📷 Output (Expected)
- Menu selection for cuisine and dish type.
- Display of selected dish details (name, type, portions/toppings/fillings).
- Demonstration of polymorphism through uniform handling of meals.

---

## ✅ Justification of Selection
This approach ensures:
- **Reusability** of base class across cuisines.
- **Flexibility** for adding new cuisines/dishes in the future.
- **Consistency** in managing attributes.
- **Polymorphism** for uniform handling of all orders.  
