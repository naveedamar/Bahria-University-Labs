# 📝 Lab08: Sub-Queries

This lab focuses on **SQL Sub-Queries** and their use in filtering, comparing, and analyzing relational data. The exercises demonstrate single-row, multi-row, and correlated sub-queries.

## 📌 Objectives

* Learn to apply **sub-queries** inside `SELECT`, `WHERE`, and `HAVING` clauses.
* Compare results across rows using single-row and multi-row operators (`=`, `>`, `<`, `ANY`, `ALL`, `IN`).
* Use sub-queries to solve problems involving departments, salaries, managers, and job roles.

## 📂 Exercises Overview

1. Find teachers in the same department as a specific teacher (`Dr. Rizwan`).
2. Retrieve details of teachers with the same job as a given teacher (`TeacherID = 9`).
3. Identify teachers earning above the average salary, sorted in descending salary order.
4. Compare salaries with a specific teacher (`Dr. Safdar`).
5. List employees who report to `Dr. Safdar`.
6. Display teachers with the same manager as a given teacher (`TeacherID = 2`) and higher salary than another (`TeacherID = 7`).
7. Show teachers earning less than the least-paid employee under a specific manager (`Manager = 5`).
8. Identify teachers whose salary equals the minimum salary for their job.
9. Find teachers with salaries greater than the average salary of all designations.
10. Retrieve teachers who earn higher than all **“J. Assist Prof”**, sorted by salary (descending).
