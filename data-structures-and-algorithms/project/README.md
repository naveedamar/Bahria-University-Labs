# 🚚 Clifton Parcel Delivery System

> An intelligent, console-based logistics solution for optimizing single-rider deliveries in the Clifton area using Graph Theory and Data Structures.

---

## 📖 About The Project

The **Clifton Parcel Delivery System** is a C++ application designed to simulate and solve the "Last Mile Delivery" problem for a specific zone. It models the delivery network as a graph and uses advanced algorithms to determine the most efficient route for a rider to deliver multiple parcels with varying priorities.

This project demonstrates the practical application of **Data Structures and Algorithms (DSA)** in solving real-world logistics challenges, specifically focusing on pathfinding and dynamic list management.

---

## ✨ Key Features

*   **📍 Smart Routing Engine:** Uses **Dijkstra’s Algorithm** to calculate the shortest path between delivery points, minimizing fuel consumption and travel time.
*   **⚡ Priority-Based Scheduling:** Automatically prioritizes "Urgent" parcels over "Normal" ones, ensuring critical deliveries are made first.
*   **🗺️ Dynamic Map Visualization:** View the internal connectivity of the Clifton area, including road distances.
*   **📦 Dynamic Parcel Management:** Add, remove, and track parcels dynamically using Linked Lists.
*   **⛽ Fuel Cost Estimation:** Provides an estimated "fuel cost" (total distance traveled) for the generated route.

---

## ⚙️ Technical Architecture

The system is built upon robust C++ fundamentals and core DSA concepts:

### Data Structures
*   **Graph (Adjacency Matrix):** Represents the map of Clifton. Nodes are locations (e.g., Boat Basin, Sea View), and edges are the roads with weights representing distance.
*   **Singly Linked List:** Manages the dynamic queue of parcels. This allows for O(1) insertion of new orders and flexible deletion.
*   **Structs:** Used to encapsulate Parcel data (Name, Location, Priority, Status).

### Algorithms
*   **Dijkstra's Shortest Path Algorithm:** The core engine that finds the optimal path from the rider's current location to the next destination.
*   **Greedy Selection Strategy:** A custom heuristic that selects the next best parcel by weighing Priority vs. Proximity.

---

## 🚀 Getting Started

### Prerequisites
*   A C++ Compiler (GCC, Clang, or MSVC).
*   An IDE (Visual Studio, CLion, VS Code) or a terminal.

### Compilation & Run
1.  **Clone or Download** the repository.
2.  **Navigate** to the project directory.
3.  **Compile** the code:
    ```bash
    g++ project.cpp -o delivery_system
    ```
4.  **Run** the executable:
    ```bash
    ./delivery_system
    ```

---

## 🎮 Usage Guide

Upon running the application, you will be presented with the main menu:

```text
=============================================
 CLIFTON PARCEL DELIVERY SYSTEM (SINGLE RIDER)
=============================================
1 Insert Parcel
2 Delete Parcel
3 Mark Delivered
4 Show Best Route
5 View Clifton Map
0 Exit
```

### 1. Insert Parcel
Add a new delivery task. You will be asked for:
*   **Name:** e.g., "Laptop for Ali"
*   **Location:** Select from the list (0-5).
*   **Priority:** Enter `2` for Urgent, `1` for Normal.

### 2. Delete Parcel
Remove a parcel from the list (e.g., if an order is cancelled). Enter the exact name of the parcel.

### 3. Mark Delivered
Manually update a parcel's status if it was delivered outside the automated route.

### 4. Show Best Route (The Magic 🪄)
This triggers the simulation. The system will:
*   Analyze all pending parcels.
*   Calculate the optimal path starting from the depot (Clifton Main).
*   Guide the rider step-by-step through the locations.
*   Display the total distance traveled.

### 5. View Map
Displays the connectivity graph, showing which areas are connected and the distance between them.

---

## 🗺️ Supported Locations

The system currently operates within the following zones in Clifton:
0.  **Clifton Main** (Depot/Start)
1.  **Boat Basin**
2.  **Zamzama**
3.  **Khayaban-e-Ittehad**
4.  **DHA Phase 8**
5.  **Sea View**

---

## 🔮 Future Improvements
*   **Multiple Riders:** Support for a fleet of riders delivering simultaneously.
*   **Traffic Simulation:** Add dynamic weights to edges to simulate traffic jams.
*   **File I/O:** Save and load parcel lists from a file.
*   **GUI:** Implement a graphical interface for better map visualization.
