# 📝 Lab12: Triggers

This lab focuses on the creation and behavior of **SQL Triggers**. The exercises demonstrate how triggers respond automatically to data changes, maintain historical records, and enforce business rules before invalid data enters the system.

## 📌 Objectives

* Understand how **AFTER Triggers** operate in SQL Server.
* Learn how triggers use the **inserted** and **deleted** logical tables.
* Maintain original records automatically whenever data is modified.
* Enforce validation rules by stopping invalid INSERT or UPDATE actions.

## 📂 Exercises Overview

### **1. Maintain Original Records Before Modification**

You are required to create a **replica of the Teacher table** (without any records) and then write a trigger that captures every change made to the Teacher table.
Whenever any **INSERT, UPDATE, or DELETE** occurs, the **original state of the record** must be stored in the replica table.
This ensures that historical data is preserved automatically before any modifications take place.

This exercise demonstrates the use of the **deleted** pseudo-table and how it helps maintain change logs.

---

### **2. Prevent Invalid Salary for Sr. Lecturer**

Create a trigger that restricts users from inserting or updating any record where:

* The **Job Title** is *Sr. Lecturer*, and
* The **Basic Salary** is **less than 45,000**

If such an attempt is made, the trigger must stop the operation and display an error message.
This ensures that salary rules for the Sr. Lecturer position are consistently enforced throughout the database.

This exercise highlights:

* Detecting invalid data in the **inserted** pseudo-table
* Using triggers to enforce business logic
* Stopping transactions when conditions are not met
