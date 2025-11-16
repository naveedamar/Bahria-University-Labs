## ⚡ DSA Lab 10 – Binary Search Tree (BST) Operations

### 🎯 Objectives

By completing this lab, students will be able to:

* **Insert** elements into a Binary Search Tree (BST).
* **Traverse** a BST using Pre-Order, In-Order, and Post-Order.
* **Search** for elements efficiently in a BST.
* **Delete** nodes from a BST.
* **Apply** BST concepts to real-world data problems.

---

### 📝 Exercises

#### 1. Library Management System

You are managing a large library database and must organize books by their **Book IDs** using a BST.

* **Tasks**
    * **Insert** the following Book IDs into the BST in the given order:
        $$\{25, 17, 38, 12, 22, 45, 32, 9, 50, 19, 28, 40\}$$
    * **Traverse** the BST using:
        * Pre-Order
        * In-Order
        * Post-Order
    * **Search** for a book ID.
        * If found → print "Found"
        * Else → print "Not found"
    * **Delete** a book ID from the BST.
* **Goal:** To organize books efficiently using BST search and traversal techniques.

---

#### 2. Word Search Puzzle Game

As a game developer, you need a fast lookup system for dictionary words used in a puzzle game. You decide to store words in a BST.

* **Tasks**
    * **Insert** the following words into the BST:
        {"kiwi", "dog", "banana", "apple", "cat", "grape", "peach", "lemon", "orange", "raspberry", "strawberry", "zebra"}
    * **Traverse** the BST using:
        * Pre-Order
        * In-Order
        * Post-Order
    * **Search** for a word.
        * If found → print "Found"
        * Else → print "Not found"
    * **Delete** a word from the BST.
    * **Display** the length of a specified word.
* **Goal:** To demonstrate the use of BSTs for text-based data in gaming applications.

---

#### 3. Warehouse Inventory System

You are managing a warehouse where item prices must be organized efficiently using a BST. Prices **above the average** ($13.73) lie on the right subtree and prices **below the average** lie on the left.

* **Dataset**
    $$11.0, 13.5, 9.5, 12.5, 14.0, 15.5, 8.0, 10.5, 11.5, 13.0, 15.5, 18.0, 17.5, 19.0, 17.0$$
* **Tasks**
    * a. Display all prices in **sorted order**.
    * b. Display the number of items priced **above** the average.
    * c. Display the number of items priced **below** the average.
    * d. Display the **highest** price.
    * e. Display the **lowest** price.
    * f. **Search** for a price provided by the user.
    * g. **Delete** a price provided by the user.
* **Goal:** To apply BST operations to numeric inventory data, supporting fast lookup and efficient organization.