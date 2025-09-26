SELECT *
FROM dbo.Prog;
--BSCS HAS PROGID OF 1 (FROM ABOVE QUERY)

SELECT * 
FROM dbo.Course
WHERE ProgID = 1;

--2

SELECT *
FROM STD;

SELECT StdName
FROM dbo.Std
WHERE StdName LIKE 'a%';

--3
SELECT *
FROM dbo.Prog;
--cs and it has id 1 and 2
SELECT *
FROM dbo.Course
WHERE (ProgID = 1 OR ProgID = 2) AND CreditHrsLab = 1 ;

--4
SELECT *
FROM dbo.Teacher;

SELECT TeacherName, BasicSalary
FROM dbo.Teacher
WHERE BasicSalary BETWEEN 100000 AND 200000;

--5
SELECT TeacherName, Job
FROM dbo.Teacher
WHERE Manager IS NULL;

--6
SELECT StdName
FROM dbo.Std
WHERE StdName LIKE '%N';

--7
SELECT TeacherName, BasicSalary, Job
FROM DBO.Teacher
WHERE Job != 'J. Lecturer' AND Status != 'Visiting';


--8
SELECT StdName
FROM dbo.Std
WHERE StdName NOT LIKE 'M%' 
	AND StdName NOT LIKE 'A%' 
	AND StdName NOT LIKE 'S%';

--9
SELECT StdName
FROM dbo.Std
WHERE StdName LIKE 'A%R';

--10
SELECT TeacherName
FROM dbo.Teacher
WHERE TeacherName NOT LIKE '%MO%';

--11
SELECT StdName
FROM dbo.Std
ORDER BY StdName ASC;

--12
SELECT *
FROM DBO.Teacher
ORDER BY BasicSalary DESC;
