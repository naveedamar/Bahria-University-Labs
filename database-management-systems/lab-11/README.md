# 📝 Lab11: Functions

This lab focuses on the creation and usage of **SQL Functions**. The exercises demonstrate how inline and scalar functions help encapsulate logic, return computed values, and simplify repeated queries across the database.

## 📌 Objectives

* Understand how to **create** and **use** both inline and scalar functions.
* Learn how functions improve reusability and modularity in SQL.
* Pass input parameters to return filtered or computed results.
* Retrieve aggregated and lookup-based data through function execution.

## 📂 Exercises Overview

1. **Create an inline function `perFacSal` (no parameters)** to return:

   * The **total salary of all Permanent Faculty** in the `Teacher` table.

2. **Create a scalar function `facDesignation` with a parameter**, which accepts:

   * `TeacherID` (input)
     It should return:
   * The **Designation (Job)** of that teacher.
     A final query must display all teachers along with their designations using this function.

3. **Create an inline function `StdData` with a parameter**, which accepts:

   * `Semester` (input)
     It should return:
   * The list of **all student names** enrolled in that semester.
