Select * from dbo.std;

SELECT StdID, StdName, StdDOB, StdPhone, ProgID
FROM dbo.Std;

SELECT COUNT(StdID) AS "NUMBER OF STUDETNS"
FROM dbo.Std;

SELECT * FROM dbo.Teacher;

SELECT TeacherName
FROM dbo.Teacher
WHERE Status = 'Permanent';

SELECT ProgID
FROM dbo.Prog;

SELECT *
FROM dbo.Std
WHERE ProgID = 1;

--6
SELECT StdName
FROM dbo.Std
WHERE ProgID = 1;

--7
SELECT (SUM(BasicSalary) * 12) AS [TOTAL SALARY OF ALL TEACHERS IN ONE YEAR]
FROM dbo.Teacher;

--8
SELECT COUNT(ProgID) AS [PROGRAM COUNT]
FROM dbo.Prog;

--9
SELECT TeacherName, Manager
FROM Teacher;