# Lab03: SQL Functions-I

## 🎯 Objectives
The goal of this lab is to practice the use of **Single Row Functions** in SQL `SELECT` statements.

---

## 📝 Exercises

Using the **StudentInformation** database, write SQL queries for the following:

1. **Teacher Names in Cases**  
   - Display the name and job of all teachers in both **UPPER** and **LOWER** case.

2. **Student Code Name**  
   - Create new student names by combining:
     - First 3 characters of their name  
     - Last 3 characters of their phone number.

3. **Replace Characters in Names**  
   - Replace all occurrences of the letter **'a'** with **'e'** in student names.

4. **Teachers' Years of Service**  
   - Display teacher names and the number of years they have served in the university.

5. **Faculty Born Before 2004**  
   - Show name, job, and **date of joining** (formatted as `MONTH DATE, YEAR`) for all faculty born **before Jan 31, 2004**.  
   - Ensure the date in the `WHERE` clause is also written in the same format.

6. **Students with No Phone**  
   - Display students whose **phone number is NULL**.

7. **Faculty Salary Calculation**  
   - Show teacher name and **total salary** (`Basic Salary + Conveyance + House Rent`).  
   - Note: Conveyance and House Rent may be NULL, but total salary must not be NULL.

8. **Faculty Bonus Calculation**  
   - Display teacher name, total salary, and bonus.  
   - Bonus rules:
     - **J. Lecturer** / **S. Lecturer** → 10% of basic salary  
     - **J. Assist Prof** / **S. Assist Prof** → 20% of basic salary  
     - **J. Associate Prof** / **S. Associate Prof** → 30% of basic salary  
     - **Others** → 40% of basic salary  

---

## ✅ Outcome
By completing these exercises, you will be able to:
- Use string functions (`UPPER`, `LOWER`, `SUBSTRING`, `REPLACE`).
- Work with date functions and formats.
- Handle `NULL` values in queries.
- Apply conditional logic in salary and bonus calculations.
