--t1
SELECT *
FROM dbo.Teacher;

--UPPER
SELECT UPPER(TeacherName) AS "NAME", UPPER(Job) AS "JOB"
FROM dbo.Teacher;

--LOWER
SELECT LOWER(TeacherName) AS "NAME", LOWER(Job) AS "JOB"
FROM dbo.Teacher;

--T2
SELECT *
FROM dbo.Std;

SELECT
    SUBSTRING(StdName, 1, 3) 
    + 
    SUBSTRING(CAST(StdPhone AS VARCHAR(20)), LEN(CAST(StdPhone AS VARCHAR(20))) - 2, 3) AS [NEW NAME]
FROM dbo.Std;

--T3
--BEFORE
SELECT StdName AS [NAME]
FROM dbo.Std;
--AFTER
SELECT REPLACE(StdName, 'a', 'e') AS [NAME]
FROM dbo.Std;

--T4
SELECT *
FROM dbo.Teacher;

SELECT
  TeacherName,
  DATEDIFF(YEAR, TeacherDOJ, '2025-09-16') AS [YEARS SERVED]
FROM dbo.Teacher;


--T5
SELECT
  TeacherName,
  Job,
  FORMAT(TeacherDOJ, 'MMMM dd, yyyy') AS [DATE OF JOINING]
FROM dbo.Teacher
WHERE
  TeacherDOB < '2004-01-31';

--6
SELECT *
FROM dbo.Std;

SELECT 
    StdID AS [ID],
    StdName AS [NAME] 
FROM dbo.Std
WHERE StdPhone IS NULL;

--7
SELECT *
FROM dbo.Teacher;

SELECT 
    TeacherName AS [NAME],
    (BasicSalary + ISNULL(HouseRent,0) ) AS [TOTAL SALARY]
FROM dbo.Teacher;

--8
SELECT 
    TeacherName AS [NAME],
    (BasicSalary + ISNULL(HouseRent,0) ) AS [TOTAL SALARY],
    CASE
        WHEN Job IN ('S. Lecturer','J. Lecture') THEN BasicSalary * 0.10
        WHEN Job IN ('Sr. Assist Prof','J. Assist Prof') THEN BasicSalary * 0.20
        WHEN Job IN ('Sr. Associate Prof','J. Associate Prof') THEN BasicSalary * 0.40
        ELSE BasicSalary * 0.40
    END AS [BONUS]
FROM dbo.Teacher;