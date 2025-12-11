# 📈 DSA Lab 13 – Graphs

### 🎯 Objectives

By completing this lab, students will be able to:

- **Implement Graphs** using an adjacency list representation.
- **Apply Graph Traversal Algorithms** like Breadth-First Search (BFS).
- **Analyze Graph Connectivity** to solve real-world problems.
- **Model Network Structures** and extract meaningful insights from them.

---

## 📝 Exercises

### 1. LinkedIn Network of Faculty Members (Graph & BFS)

You are building a system to model a **LinkedIn network** for faculty members at a university. The goal is to explore connections and identify influential users to foster collaboration.

The system will be implemented as a graph, where each faculty member is a node and a connection is an edge.

#### **Tasks**
- Implement the given network as a graph using an **adjacency list**.
- Apply **BFS traversal** starting from a specific user to find all their direct connections.
- Calculate and display the **average number of connections** per user.
- Identify **influential users** (those with 3 or more direct connections).

#### **Goal**
To learn how to model a social network using graphs and analyze its structure to find key connections and influencers.

---

### 2. Transportation Network of Cities (BFS)

You need to construct a program that models a simple **transportation network** of cities connected by roads. Each city is a node, and each road is an edge.

This model will help in understanding connectivity between different cities in the network.

#### **Tasks**
- Represent the network using an **adjacency list**.
- Create a graph with the following cities and roads:
  - **Cities**: City1, City2, City3, City4, City5, City6
  - **Roads**:
    - City1 is connected with City2
    - City2 is connected with City5 and City6
    - City3 is connected with City4
    - City4 is connected with City5
    - City6 is connected with City1 and City5
- Perform a **BFS traversal** to explore the connectivity of the network.

#### **Goal**
To practice building a graph from a set of specifications and using BFS to understand reachability and network structure.

---

### 3. CodeConnect: Mutual Friends (Adjacency & Set Logic)

You are designing a feature for **CodeConnect**, a social platform for developers. The task is to find the **mutual friends** between any two developers on the platform.

Each developer is a node, and a friendship is an edge.

#### **Tasks**
1.  Represent the following social network as a graph:
    - **Ashir** is friends with Hammad and Sarim.
    - **Hammad** is friends with Ashir, Sarim, and Muneeb.
    - **Sarim** is friends with Ashir, Hammad, Muneeb, and Izhan.
    - **Muneeb** is friends with Hammad, Sarim, and Izhan.
    - **Izhan** is friends with Sarim and Muneeb.
2.  Implement a function that takes two developer names and **finds their mutual friends**.

#### **Goal**
To use graph adjacency information to solve a common social network problem by comparing the connection lists of two different nodes.
