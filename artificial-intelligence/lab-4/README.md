# AI Lab 04: Informed Search - A* Algorithm

---

## 📝 Task Description
The objective of this lab was to implement the **A* Search Algorithm** to find the most efficient path between a start node and a goal node in a weighted graph.

The program utilizes:
* **Graph Representation:** An adjacency list where each node points to its neighbors and the path cost $g(n)$.
* **Heuristics:** A dictionary providing the estimated cost $h(n)$ from each node to the goal.
* **Priority Queue:** A min-heap to always expand the node with the lowest total estimated cost $f(n) = g(n) + h(n)$.



---

## 📝 Path Exploration
In addition to the implementation, a supplementary text file was created to document the exploration of various possible routes within the graph.
* **Optimal Path:** The code identifies the path with the minimum total cost from 'S' to 'G'.
* **Secondary Paths:** All non-optimal routes explored during the search process were recorded to understand the algorithm's traversal behavior.