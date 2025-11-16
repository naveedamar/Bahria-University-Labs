# 📝 Lab10: Stored Procedures

This lab focuses on the creation and execution of **SQL Stored Procedures**. The exercises demonstrate how stored procedures can encapsulate logic, accept parameters, return results, and simplify repeated operations within a database environment.

## 📌 Objectives

- Understand how to **create**, **execute**, and **parameterize** stored procedures.  
- Learn how stored procedures enhance reusability and maintainability.  
- Use input parameters to filter and compute results dynamically.  
- Retrieve aggregated, filtered, and joined data through procedure execution.  

## 📂 Exercises Overview

1. **Create a stored procedure `DISPLAY` (no parameters)** to show:  
   - `TeacherID`, `TeacherName`, `BasicSalary`  
   for all faculty members with **Permanent** status.

2. **Create a stored procedure `DISPLAY2` with parameters** that accepts:  
   - `Status` (input)  
   It should return:  
   - Total count of employees with that status  
   - Total salary of employees under that status.

3. **Create a stored procedure `DISPLAY3` with parameters** that accepts:  
   - `Semester` (input)  
   It should return:  
   - Student Name  
   - Lowest Marks  
   - Highest Marks  
   in the **Final Exam** for the selected semester.

4. **Create a stored procedure `DISPLAY4`** that lists all subjects taught by teachers whose **Job = 'Sr. Lecturer'**.  
   The output includes full subject/course information and teacher assignment.

5. **Create a stored procedure** to display all courses taught in:  
   - **Second Semester**, and  
   - Having **Credit Hours = 3 + 1 (Theory**
