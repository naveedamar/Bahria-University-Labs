# 🧮 DSA Lab 06 – Queue and Circular Queue

---

## 🎯 Objectives

By completing this lab, students will be able to:

* Understand and implement the **concept of queue** and **circular queue**.
* Apply queue operations (`enQueue`, `deQueue`, `display`) in practical scenarios.
* Handle **overflow** and **underflow** conditions in queues.
* Use queues to model **real-world problems** such as package delivery, rides, ticket booking, and checkout systems.

---

## 📝 Exercises

### 1. Efficient Package Management – Emily's Logistics Queue System

Implement a **queue** with max capacity **6 packages**.

* `enQueue()` – Add a package to delivery queue.
* `deQueue()` – Remove a delivered package.
* `Display()` – Show all packages in the queue.

**Test Procedure:**

1. Add 6 packages (10, 7, 4, 8, 2, 15).  
2. Display queue.  
3. Try adding another package (25).  
4. Remove 2 packages.  
5. Display updated queue.  

---

### 2. Thrilltopia – Thunder Coaster

Implement a **queue** system for a roller coaster with max **10 customers**.

* `enQueue()` – Add customer to queue.  
* `deQueue()` – Remove **all 10 customers** when ride starts.  
* `Display()` – Show queue status (empty after ride).  

**Rule:** All 10 customers board together, then queue resets.  

---

### 3. Ticket Booking System – Movie Theater

Use a **circular queue** with max **6 tickets**.

* `enQueue()` – Add ticket.  
* `deQueue()` – Remove booked ticket.  
* `Display()` – Show available tickets.  

**Use Case:** Manage ticket booking system efficiently.  

---

### 4. FreshMart’s Checkout System

Implement a **circular queue** for a grocery store with max **10 customers**.

* `enQueue()` – Add customer to checkout line.  
* `deQueue()` – Remove customer after billing.  
* Handle errors:
  - Empty queue → No customer to checkout.  
  - Full queue → Cannot add more customers.  

**Use Case:** Simulate customer checkout process at a grocery store.  

---

## 📂 Key Concepts

* **Queue operations** (`enQueue`, `deQueue`, `display`)  
* **Circular queue mechanics** (wrap-around)  
* Handling **queue overflow** and **underflow**  
* Queue applications in:
  * **Logistics & delivery**
  * **Theme park rides**
  * **Ticket booking**
  * **Retail checkout systems**
