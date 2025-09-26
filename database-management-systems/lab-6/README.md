# 📘 Lab06: DDL Queries & SQL Constraints

## 🎯 Objectives
- Learn **Data Definition Language (DDL)**  
- Apply **Constraints** on tables  
- Represent ER Model using **ER Diagram**

## 📝 Exercises
Using the **StudentInformation** database, write SQL DDL queries for:

1. Create a replica of **Teacher** table with all records.  
2. Create a replica of **Std** table with only BSCS students.  
3. Add a column `Address` in replicated Teacher table.  
4. Drop column `Address` from replicated Teacher table.  
5. Add columns `House No` (char), `Street No` (numeric), `Area` (char), `City` (char).  
6. Change data type of `House No` from char to numeric.  
7. Create the following tables with given attributes and constraints:  

   - **FACULTY**: `FacultyID (PK)`, `FacultyName (varchar(25))`  
   - **COURSE**: `CourseID (PK)`, `CourseName (varchar(15))`  
   - **CLASS**: `ClassID (PK)`, `CourseID (FK)`, `SectionNo`, `Semester`  
   - **STUDENT**: `StudentID (PK)`, `StudentName (varchar(25))`, `FacultyID (FK)`  

8. Add attributes `Class` and `Phone` to **STUDENT** table.  
9. Change size of `StudentName` from 25 to 20 characters.  
10. Remove all records from **STUDENT** table.  
11. Remove **Faculty** and **Course** tables.  
12. Create **DEPARTMENT** table: `DEPTNO (PK)`, `DNAME`, `LOC`.  
13. Create **EMPLOYEE** table: `EMPNO (PK)`, `ENAME`, `SAL`, `DEPTNO (FK → DEPARTMENT)`.  
14. Alter **EMPLOYEE**: Add `CHECK` so `ENAME` is always in capital letters.  
15. Alter **DEPARTMENT**: Add constraint so `DNAME` cannot be empty.  
16. Alter **EMPLOYEE**: Add constraint so no two employees have the same `SAL`.  
17. Alter **DEPARTMENT**: Add constraint so no two departments have the same `DNAME`.  
