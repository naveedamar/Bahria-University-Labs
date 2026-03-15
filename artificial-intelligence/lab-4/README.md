# AI Lab 04: Search Algorithms

---

## 📝 Task 1: Informed Search - A* Algorithm
The objective of this task was to implement the A* Search Algorithm to find the most efficient path between a start node and a goal node in a weighted graph.
A supplementary text file was also created to document the exploration of various possible routes within the graph, tracking both the optimal path and secondary paths.

## Path Exploration
In addition to the implementation, a supplementary text file was created to document the exploration of various possible routes within the graph.
* **Optimal Path:** The code identifies the path with the minimum total cost from 'S' to 'G'.
* **Secondary Paths:** All non-optimal routes explored during the search process were recorded to understand the algorithm's traversal behavior.

---

## 📝 Task 2: Facebook Network DFS
The objective of this task was to construct a graph representing a Facebook network and apply Depth-First Search (DFS) to find a communication path between two specific users.

**Network Conditions:**
* Each person’s account is a node in a graph.
* Amina is a mutual friend of Sara and Razi.
* Razi is a mutual friend of Ali and Ahmed.
* Ahmed is a mutual friend of Ahsan.
* Rida is a mutual friend of Hassan and Taha.
* Uzma is a mutual friend of Ahsan and Taha.
* Distance of each link is 1.

**Search Requirement:**
Apply DFS to find and display the path for Sara to communicate a message to Uzma.

**Resulting Path:**
Sara -> Amina -> Razi -> Ahmed -> Ahsan -> Uzma