--LAB 5
SELECT *
FROM Course ;

SELECT *
FROM Prog;

SELECT *
FROM Semester;

SELECT *
FROM dbo.Std;

SELECT *
FROM Teacher;

SELECT *
FROM StdCourseTeacher;

--T1
SELECT co.CourseID, co.CourseName, pr.ProgName
FROM Course AS [co]
INNER JOIN Prog AS [pr] ON co.ProgID = pr.ProgID;


--T2
SELECT co.CourseID, co.CourseName, pr.ProgName, sem.SemName
FROM Course AS [co]
INNER JOIN Prog AS [pr] ON co.ProgID = pr.ProgID
INNER JOIN Semester AS [sem] ON sem.SemID = co.Semester;

--T3

--inserting into the table std
SET IDENTITY_INSERT [dbo].[Std] ON;

-- Program 2 students (StdID 11–20)
INSERT [dbo].[Std] ([StdID], [StdName], [StdDOB], [FirstSem], [StdPhone], [StdAddress], [StdEmail], [GuardianContact], [ProgID]) 
VALUES 
(11, N'Bisma',   CAST(0x8ECC0000 AS SmallDateTime), 1, N'03022345678', NULL, NULL, NULL, 2),
(12, N'Sadia',   CAST(0x901A0000 AS SmallDateTime), 1, N'03122345678', NULL, NULL, NULL, 2),
(13, N'Sarah',   CAST(0x90590000 AS SmallDateTime), 3, N'03033456789', NULL, NULL, NULL, 2),
(14, N'Namra',   CAST (0x90C30000 AS SmallDateTime), 3, N'03133456789', NULL, NULL, NULL, 2),
(15, N'Waqar',   CAST(0x8E3B0000 AS SmallDateTime), 1, N'03322345678', NULL, NULL, NULL, 2),
(16, N'Noman',   CAST(0x91060000 AS SmallDateTime), 3, N'03333456789', NULL, NULL, NULL, 2),
(17, N'Abrar',   CAST(0x901E0000 AS SmallDateTime), 4, N'03422345678', NULL, NULL, NULL, 2),
(18, N'Mohsin',  CAST(0x906B0000 AS SmallDateTime), 4, N'03433456789', NULL, NULL, NULL, 2),
(19, N'Sikandar',CAST(0x91190000 AS SmallDateTime), 6, N'03622345678', NULL, NULL, NULL, 2),
(20, N'Javed',   CAST(0x913F0000 AS SmallDateTime), 6, N'03522345678', NULL, NULL, NULL, 2);

-- Program 3 students (StdID 21–30)
INSERT [dbo].[Std] ([StdID], [StdName], [StdDOB], [FirstSem], [StdPhone], [StdAddress], [StdEmail], [GuardianContact], [ProgID]) 
VALUES 
(21, N'Bisma',   CAST(0x8ECC0000 AS SmallDateTime), 1, N'03032345678', NULL, NULL, NULL, 3),
(22, N'Sadia',   CAST(0x901A0000 AS SmallDateTime), 1, N'03132345678', NULL, NULL, NULL, 3),
(23, N'Sarah',   CAST(0x90590000 AS SmallDateTime), 3, N'03044456789', NULL, NULL, NULL, 3),
(24, N'Namra',   CAST(0x90C30000 AS SmallDateTime), 3, N'03144456789', NULL, NULL, NULL, 3),
(25, N'Waqar',   CAST(0x8E3B0000 AS SmallDateTime), 1, N'03332345678', NULL, NULL, NULL, 3),
(26, N'Noman',   CAST(0x91060000 AS SmallDateTime), 3, N'03344456789', NULL, NULL, NULL, 3),
(27, N'Abrar',   CAST(0x901E0000 AS SmallDateTime), 4, N'03432345678', NULL, NULL, NULL, 3),
(28, N'Mohsin',  CAST(0x906B0000 AS SmallDateTime), 4, N'03444456789', NULL, NULL, NULL, 3),
(29, N'Sikandar',CAST(0x91190000 AS SmallDateTime), 6, N'03632345678', NULL, NULL, NULL, 3),
(30, N'Javed',   CAST(0x913F0000 AS SmallDateTime), 6, N'03532345678', NULL, NULL, NULL, 3);

SET IDENTITY_INSERT [dbo].[Std] OFF;

SELECT std.ProgID, std.StdName
FROM dbo.Std AS [std]
INNER JOIN Prog AS [pr] ON std.ProgID = pr.ProgID
WHERE std.ProgID != 1;	

--T4
SELECT tea.TeacherName, cour.CourseName
FROM dbo.Teacher AS [tea]
INNER JOIN StdCourseTeacher AS [courTea] ON tea.TeacherID = courTea.TeacherID
INNER JOIN Course AS [cour] ON courTea.CourseID = cour.CourseID
WHERE tea.Status = 'Visiting';	

--T5

--ADDING DATA
USE [stud-data];
GO
SET IDENTITY_INSERT dbo.Semester ON;

INSERT INTO dbo.Semester (semID, SemName, startDate)
VALUES
(7, 'Fall2022',   '2022-09-01'),
(8, 'Spring2023', '2023-02-01'),
(9, 'Fall2023',   '2023-09-01'),
(10, 'Spring2024','2024-02-01'),
(11, 'Fall2024',  '2024-09-01'),
(12, 'Spring2025','2025-02-01'),
(13, 'Fall2025',  '2025-09-01');

SET IDENTITY_INSERT dbo.Semester OFF;



--QUERY
SELECT cour.CourseID, cour.CourseName
FROM Teacher AS tea
INNER JOIN StdCourseTeacher AS courTea ON tea.TeacherID = courTea.TeacherID
INNER JOIN Course AS cour ON cour.CourseID = courTea.CourseID
INNER JOIN Semester AS sem ON sem.SemID = courTea.SemID
WHERE courTea.TeacherID = (
    SELECT TeacherID
    FROM Teacher
    WHERE TeacherName LIKE '%Iman%'
)
AND sem.SemName = 'Fall2020';

--T6
SELECT cour.CourseID, cour.CourseName, tea.TeacherName
FROM Course AS [cour]
INNER JOIN StdCourseTeacher AS [courTea] ON cour.CourseID = courTea.CourseID
INNER JOIN Teacher AS [tea] ON tea.TeacherID = tea.TeacherID;

--T7
SELECT cour.CourseName, Std.StdName, tea.TeacherName
FROM Course AS [cour]
INNER JOIN Std ON cour.ProgID = Std.ProgID
INNER JOIN Teacher AS [tea] ON tea.TeacherID = tea.TeacherID
WHERE tea.TeacherName LIKE '%AHMED%';

--T8
SELECT 
    std.StdID, std.StdName, cour.CourseID, cour.CourseName, 
    tea.TeacherID, tea.TeacherName, sem.SemID, sem.SemName
FROM Std AS std
INNER JOIN StdCourseTeacher AS sct ON std.StdID = sct.StdID
INNER JOIN Course AS cour ON sct.CourseID = cour.CourseID
INNER JOIN Teacher AS tea ON sct.TeacherID = tea.TeacherID
INNER JOIN Semester AS sem ON sct.SemID = sem.SemID;

--T9
SELECT DISTINCT tea.TeacherID, tea.TeacherName
FROM Teacher AS tea
INNER JOIN StdCourseTeacher AS sct ON tea.TeacherID = sct.TeacherID
INNER JOIN Semester AS sem ON sct.SemID = sem.SemID
WHERE sem.SemName = 'Fall2021';

--T10
SELECT DISTINCT t.TeacherID, t.TeacherName
FROM Teacher AS t
INNER JOIN StdCourseTeacher AS sct ON t.TeacherID = sct.TeacherID;

--T11
SELECT t.TeacherID, t.TeacherName, c.CourseName
FROM Teacher AS t
LEFT JOIN StdCourseTeacher AS sct ON t.TeacherID = sct.TeacherID
LEFT JOIN Course AS c ON sct.CourseID = c.CourseID
WHERE CourseName IS NOT NULL;

--T12
SELECT t.TeacherID, t.TeacherName, NULL AS CourseID, NULL AS SemID
FROM Teacher AS t
LEFT JOIN StdCourseTeacher AS sct ON t.TeacherID = sct.TeacherID
WHERE sct.TeacherID IS NULL;

--T13
SELECT sem.SemID, sem.SemName, 
    COUNT(sct.StdID) AS NumOfStudents
FROM Semester AS sem
LEFT JOIN StdCourseTeacher AS sct ON sem.SemID = sct.SemID
GROUP BY sem.SemID, sem.SemName
HAVING COUNT(sct.StdID) = 0;
