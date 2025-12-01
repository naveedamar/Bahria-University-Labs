# 📝 Lab13: Entity Relationship Diagrams (ERDs)

> **Note:** This lab is **diagram-based**, meaning the primary task is to analyze each scenario and create the **ERD diagrams** visually. The written content below guides the conceptual understanding, while the actual diagrams must be inserted using image placeholders.

## 📌 Objectives

* Understand how to **identify entities, attributes, and relationships** from word-based scenarios.
* Analyze **cardinality** and **participation constraints**.
* Model complex relationships such as **multi-valued attributes**, **recursive relationships**, and **associative entities**.
* Produce correct and complete **ERD diagrams** for each scenario.

---

## 📂 Scenario 1 — Company, Departments, Employees, Projects & Dependents

### **Key Entities**

* Department
* DepartmentLocation (multi-valued)
* Employee
* Project
* WorksOn
* Dependent

### **Key Relationships**

* A Department is managed by an Employee.
* A Department has multiple Locations.
* A Department controls multiple Projects.
* An Employee belongs to one Department.
* An Employee may work on multiple Projects (with hours per week).
* An Employee has a Supervisor (recursive).
* An Employee has multiple Dependents.

### **ERD Diagram**
![Scenario 1 ERD](database-management-systems/lab-13/s1.jpg)

---

## 📂 Scenario 2 — Customers, Orders, Products, Order Lines, Invoices

### **Key Entities**

* Customer
* Order
* OrderLine
* Product
* Invoice

### **Key Relationships**

* A Customer places multiple Orders.
* An Order has multiple OrderLines.
* Each OrderLine references one Product.
* Each Order has exactly one Invoice.

### **ERD Diagram**
![Scenario 2 ERD](database-management-systems/lab-13/s2.jpg)


---

## 📂 Scenario 3 — Suppliers, Items, Products, Shipments, Customers, Orders

### **Key Entities**

* Supplier
* Item
* Product
* Shipment
* ShipmentItem
* Customer
* Order
* OrderProduct

### **Key Relationships**

* A Supplier supplies multiple Items (M–N).
* An Item is used in multiple Products (M–N).
* A Supplier sends multiple Shipments.
* A Shipment contains multiple Items (M–N).
* A Customer submits multiple Orders.
* An Order requests multiple Products (M–N).

### **ERD Diagram**
![Scenario 3 ERD](database-management-systems/lab-13/s3.jpg)
