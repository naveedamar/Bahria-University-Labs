# 📝 Lab09: Views in SQL

This lab focuses on the creation, usage, and manipulation of **SQL Views**. The exercises demonstrate how views can simplify data retrieval, encapsulate logic, and provide a secure, abstracted layer over underlying tables.

## 📌 Objectives

- Understand how to **create**, **query**, and **update** SQL Views.  
- Learn how views interact with underlying tables.  
- Perform data updates through views.  
- Use views for aggregation, joins, and computed attributes such as **percentage** and **GPA**.  
- Explore the behavior of views when underlying tables do not yet exist.

## 📂 Exercises Overview

1. **Create a view for semesters with `SemID > 3`**, displaying:  
   - `SemID`, `SemName`, `StartDate`.

2. **Create `StdInformation_vw`** to show student information:  
   - `StdID`, `StdName`, `StdDOB`, `ProgID`, `FirstSem`.

3. **Update student data through the view** by changing Abrar’s `FirstSem` from 4 to 3, then display the updated results.

4. **Create a joined view** using Semester, Course, and Prog tables to display:  
   - `CourseName`, `CreditHrsTheory`, `CreditHrsLab`, `ProgName`, `SemName`.

5. **Create a teacher view** that shows information of teachers who teach semester **4** and **6**.

6. **Create an aggregated view** showing the **sum of salaries grouped by job**.

7. **Create a percentage-calculation view** using marks obtained relative to maximum marks.

8. **Create a GPA-calculation view** using the percentage results from task 7.

9. **Create a view (`MY_VU`)** on a non-existing table (`NewTeacher`), then create `NewTeacher` from Teacher records with `Status = 'Visiting'`, and fina**_**
