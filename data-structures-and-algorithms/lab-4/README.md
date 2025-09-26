# 🧮 DSA Lab 04 – Algorithm Analysis

**Course:** CSL-221 Data Structures & Algorithms  

---

## 🎯 Objectives
By completing this lab, students will be able to:
- Experimentally analyze the **time complexity** of algorithms.  
- Measure both **execution time** (using `clock()`) and **number of steps** (loop iterations).  
- Compare recursive and iterative approaches.  

---

## 📝 Exercises

1. **Library Books Sorting**  
   - Implement and analyze the following algorithms on a set of book titles:  
     - **Bubble Sort**  
     - **Selection Sort**  
     - **Insertion Sort**  
   - Measure:  
     - Execution time (`clock()`)  
     - Number of steps (loop iterations)  
   - Compare results and discuss efficiency.

2. **Searching Employee IDs**  
   - Implement:  
     - **Linear Search**  
     - **Binary Search**  
   - Dataset: 100 employee IDs (sequential).  
   - Measure execution time and loop steps.  
   - Compare search efficiency between linear and binary search.  

3. **Star Pyramid**  
   - Print a pyramid of stars (`N` rows).  
   - Test for values: **N = 10, 15, 25, 50, 100**.  
   - Count operations (loop iterations) and analyze growth.  
   - Complexity: `O(N²)`.

4. **Recursion vs Iteration (Factorial)**  
   - Implement factorial using:  
     - **Recursive approach**  
     - **Iterative approach**  
   - Test for values: **n = 10, 50, 100, 150, 200, 250, 300**.  
   - Measure execution time and steps.  
   - Plot graph: **execution time vs n**.  
   - Compare results and conclude which is more efficient.  

---

## 📂 Key Concepts
- **Sorting:** Bubble, Selection, Insertion  
- **Searching:** Linear vs Binary  
- **Pattern Printing:** Complexity analysis  
- **Recursion vs Iteration:** Trade-offs in efficiency  

---

## 📊 Analysis Summary
- Sorting algorithms: all **O(N²)**, but performance varies.  
- Searching: Binary search far more efficient than linear on sorted data.  
- Star pyramid: Quadratic growth with number of rows.  
- Factorial: Iterative approach is faster and more scalable than recursion.  
