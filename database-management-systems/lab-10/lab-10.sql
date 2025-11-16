--lab 10: Stored Procedures
--Objective: To learn the Stored Procedures
USE Stud_Info
GO;


--1.	Create a stored procedure DISPLAY without parameters. 
--The procedure must display Teacher ID, Teacher Name and BasicSalary of all the Faculty that are permanent. 
CREATE PROCEDURE DISPLAY
AS
BEGIN
SELECT TeacherID, TeacherName, BasicSalary
FROM Teacher
WHERE Status = 'Permanent'
END

EXEC DISPLAY;

--2.	Create a stored procedure DISPLAY2 with parameters. 
--It must take Status as an input and must return the Count of Employee related to the status and Total Salary of the input Status.
CREATE PROCEDURE DISPLAY2
@STATUS VARCHAR(20)
AS
BEGIN
SELECT COUNT(TeacherID) AS [IDs], SUM(BasicSalary) AS [TOTAL SALARIES]
FROM Teacher
WHERE Status = @STATUS
END

EXEC DISPLAY2 'Visiting';

--3.	Create a stored procedure DISPLAY3 with parameters. 
--It must take Semester as an input and must return the Student Name, Lowest and Highest Marks of final exam of the inputted Semester. 
--FINAL HAS EXAM ID 4
CREATE PROCEDURE DISPLAY3
    @SEM TINYINT
AS
BEGIN
    SELECT 
        S.StdName,
        SM.MarksObtained AS [Marks],
        (SELECT MIN(MarksObtained) 
         FROM StdMarks M
         INNER JOIN Exam E ON M.ExamID = E.ExamID
         WHERE E.SemID = @SEM AND E.ExamID = 4) AS LowestMarks,

        (SELECT MAX(MarksObtained) 
         FROM StdMarks M
         INNER JOIN Exam E ON M.ExamID = E.ExamID
         WHERE E.SemID = @SEM AND E.ExamID = 4) AS HighestMarks
    FROM Std S
    INNER JOIN StdMarks SM ON SM.StdID = S.StdID
    INNER JOIN Exam E ON SM.ExamID = E.ExamID
    WHERE E.ExamID = 4 AND E.SemID = @SEM;
END

EXEC DISPLAY3;

--4.	Create a Stored procedure DISPLAY4 that displays the information of all the subjects that are being taught by the teachers 
--whose Job is ‘Sr. Lecturer’.
CREATE PROCEDURE DISPLAY4
AS
BEGIN
    SELECT 
        C.CourseID        AS [COURSE ID],
        C.CourseName      AS [COURSE NAME],
        SCT.TeacherID     AS [TEACHER ID],
        C.CreditHrsTheory AS [THEORY CR],
        C.CreditHrsLab    AS [LAB CR],
        C.ProgID          AS [PROGRAM ID],
        C.Semester        AS [SEMESTER]
    FROM Course AS C
    INNER JOIN StdCourseTeacher AS SCT 
        ON SCT.CourseID = C.CourseID
    INNER JOIN Teacher AS T 
        ON T.TeacherID = SCT.TeacherID
    WHERE T.Job = 'S. Lecturer';
END

EXEC DISPLAY4;

--5.	Create a stored procedure that will display the information of all the courses that are taught in second semester and are of credit hours 3+1. 
CREATE PROCEDURE DISPLAY5
AS
BEGIN
    SELECT 
        CourseID      AS [COURSE ID],
        CourseName    AS [COURSE NAME],
        CreditHrsTheory AS [THEORY CR],
        CreditHrsLab    AS [LAB CR],
        ProgID        AS [PROGRAM ID],
        Semester      AS [SEMESTER]
    FROM Course
    WHERE Semester = 2
      AND CreditHrsTheory = 3
      AND CreditHrsLab = 1;
END

EXEC DISPLAY5
