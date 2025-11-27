# ⚡ DSA Lab 11 – Heap Sort & Priority Queue

### 🎯 Objectives

By completing this lab, students will be able to:

- **Implement Heap Sort** for efficient array sorting.  
- **Build and manage Priority Queues** using heaps.  
- **Apply Max-Heap and Min-Heap concepts** to real-world data scenarios.  

---

## 📝 Exercises

### 1. Cricket Player Performance (Max Heap)

You are managing a cricket team and need an efficient way to rank players based on their **performance ratings**. To assist in team selection and management, you will use a **Max Heap** so that the highest-rated player always rises to the top.

#### **Tasks**
- Insert multiple **player names** along with their **performance ratings**.
- Build a **Max Heap** to organize the players.
- Display the **player list** as arranged in the heap.
- Find the **highest-rated player** (root of Max Heap).
- Delete a player from the heap (e.g., dropped/injured).

#### **Goal**
To understand how a Max Heap helps in ranking and prioritizing top-performing players efficiently.

---

### 2. Prioritizing Recipes by Cooking Time (Min Heap + Heap Sort)

A cooking application needs to manage recipes based on **cooking time**. Faster recipes should appear first, so a **Min Heap** is ideal.

#### **Tasks**
- Insert recipe names along with their **cooking times**.
- Build a **Min Heap** so the shortest cooking time stays at the root.
- Display all recipes as arranged in the heap.
- Perform **Heap Sort** to sort recipes **in increasing order** of cooking time.
- Find and display the **recipe with the shortest cooking time**.

#### **Goal**
To practice Min Heap operations and apply Heap Sort for real-world scheduling and time-prioritization problems.

---

### 3. Patient’s Priority Queue

A clinic receives patients from different categories. To treat them fairly and efficiently, you must implement a **Priority Queue** where priority is based on patient type rather than arrival time.

#### **Priority Levels**
1. Emergency Patient  
2. Old Age Patient  
3. Children  
4. New Patient  
5. Regular Patient  

#### **Scenario**
Patients arrive in a normal FIFO manner, but Dr. ABC attends them **based on priority**, not arrival order. You must simulate this behaviour using a priority queue.

---

### **Goal**
To demonstrate how priority queues reorder items based on urgency, not sequence, allowing efficient service management.
