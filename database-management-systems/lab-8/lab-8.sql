/*
Objectives:
	To learn to use Sub-Queries to solve problems.
*/

USE [stud-data];
GO
--Tasks

/*
1.	Write a query to display TeacherName and HireDate for all teachers in the same department as ‘Dr. Rizwan’
*/
SELECT tea.TeacherName, tea.TeacherDOJ
FROM Teacher AS [tea]
INNER JOIN StdCourseTeacher AS [courseTea] ON tea.TeacherID = courseTea.TeacherID
INNER JOIN Course AS [course] ON courseTea.CourseID = course.CourseID
WHERE course.ProgID = (
    SELECT ProgID
    FROM Teacher
    WHERE TeacherName = 'Dr. Rizwan'
);

--no teacher shares dr.rizwans dept

/*
2.	Write a query to display TeacherID, Name, Salary of all teachers who have the same job as TeacherID = 9.  
*/
SELECT TeacherID, TeacherName, BasicSalary
FROM Teacher
WHERE Job = (
    SELECT Job
    FROM Teacher
    WHERE TeacherID = 9
);

/*
3.	Write a query to display the TeacherID and Name for all teachers who earn more than the Average Salary. Sort the result in descending order of salary.
*/
SELECT TeacherID AS [ID], TeacherName AS [NAME] 
FROM Teacher
WHERE BasicSalary > (
    SELECT AVG(BasicSalary)
    FROM Teacher
)
ORDER BY BasicSalary DESC;

/*
4.	Write a query to display TeacherID, Name and Job of all teachers who are earning more than Dr. Safdar.
*/
SELECT TeacherID AS [ID], TeacherName AS [NAME], Job AS [JOB]
FROM Teacher
WHERE BasicSalary > (
    SELECT BasicSalary
    FROM Teacher
    WHERE TeacherName = 'Dr. Safdar'
);

/*
5.	Display Teacher Name and Salary of all employees who report to ‘Dr. Safdar’
*/
SELECT TeacherName AS [NAME], BasicSalary AS [SALARY]
FROM Teacher
WHERE Manager = (
    SELECT TeacherID
    FROM Teacher
    WHERE TeacherName = 'Dr. Safdar'
);

/*
6.	Write a query to display Teacher Name and Job of all teachers who same Manager as TeacherID = 2 and Salary greater than TeacherID = 7
*/
SELECT TeacherName AS [NAME], Job AS [JOB]
FROM Teacher
WHERE Manager = (
    SELECT Manager
    FROM Teacher
    WHERE TeacherID = 2
)
AND 
BasicSalary > (
    SELECT BasicSalary
    FROM Teacher
    WHERE TeacherID = 7
);

/*
7.	Write a query to display TeacherID, TeacherName and Manager of all teachers who earn less than the least earning employee of Manager = 5.
*/
SELECT TeacherID AS [ID], TeacherName AS [NAME], Manager AS [MANAGER ID]
FROM Teacher
WHERE BasicSalary < (
    SELECT MIN(BasicSalary)
    FROM Teacher
    WHERE Manager = 5
);

/*
8.	Write a query to display TeacherID, TeacherName of all teachers whose salary is equivalent to Minimum Salary of their Job.
*/
SELECT TeacherID AS [ID], TeacherName AS [NAME]
FROM Teacher T
WHERE BasicSalary = (
    SELECT MIN(BasicSalary)
    FROM Teacher
    WHERE Job = T.Job
);

/*
9.	Write a query to display TeacherID, TeacherName, and Job of all Teachers whose salary is greater than the Average Salary of all designations.
*/
SELECT TeacherID AS [ID], TeacherName AS [NAME], Job AS [JOB]
FROM Teacher
WHERE BasicSalary > (
    SELECT AVG(BasicSalary)
    FROM Teacher
);

/*
10.	Write a query to display teachers that earn higher than all “J. Assist Prof”. Sort the results in descending order with respect to Salary.
*/
SELECT *
FROM Teacher
WHERE BasicSalary > (
    SELECT MAX(BasicSalary)
    FROM Teacher
    WHERE Job = 'J. Assist Prof'
)
ORDER BY BasicSalary DESC;
