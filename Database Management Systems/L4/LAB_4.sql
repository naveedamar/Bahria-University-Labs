SELECT * 
FROM dbo.Teacher;

--T1
SELECT 
	Job AS [JOB],
	AVG(BasicSalary) AS [AVERAGE SALARY]
FROM dbo.Teacher
GROUP BY Job;

--T2
SELECT 
	Job AS [JOB],
	AVG(BasicSalary) AS [AVERAGE SALARY],
	MAX(BasicSalary) AS [MAX SALARY],
	MIN(BasicSalary) AS [MIN SALARY],
	SUM(BasicSalary) AS [SUM SALARY]
FROM dbo.Teacher
GROUP BY Job;

--T3
SELECT
  Job AS [JOB],
  AVG(BasicSalary + HouseRent) AS [AVERAGE SALARY]
FROM dbo.Teacher
GROUP BY Job
HAVING AVG(BasicSalary + HouseRent) > 150000;

--T4
SELECT
  Job AS [DESIGNATION],
  MAX(BasicSalary) AS [MAXIMUM SALARY]
FROM dbo.Teacher
GROUP BY Job
HAVING MAX(BasicSalary) > 250000
ORDER BY [MAXIMUM SALARY] DESC;

--T5
SELECT 
	Job AS [JOB],
	AVG(BasicSalary) AS [AVERAGE SALARY],
	COUNT(Manager) AS [NUMBER OF MANAGERS]
FROM dbo.Teacher
GROUP BY Job;

--T6
SELECT COUNT(TeacherID)
FROM dbo.Teacher
WHERE HouseRent IS NULL OR HouseRent = 0;


--T7
SELECT 
	Job AS [DESIGNATION],
	COUNT(Job) AS [STAFF NUMBER]
FROM dbo.Teacher
GROUP BY Job;

--T8
SELECT 
	Job AS [DESIGNATION],
	MAX(BasicSalary) - MIN(BasicSalary) AS [DIFF B/T MAX & MIN SALARY]
FROM dbo.Teacher
GROUP BY Job;

--T9
SELECT
  Manager,
  MIN(BasicSalary) AS [MINIMUM SALARY]
FROM dbo.Teacher
WHERE Manager IS NOT NULL
GROUP BY Manager
ORDER BY [MINIMUM SALARY] DESC;

--10
SELECT
  Job AS [Job Title],
  COUNT(*) AS [Number of Employees],
  ROUND(AVG(BasicSalary + ISNULL(HouseRent, 0)), 2) AS [Average Salary]
FROM dbo.Teacher
GROUP BY Job;