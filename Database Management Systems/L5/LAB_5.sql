--LAB 5
SELECT *
FROM Course ;

SELECT *
FROM Prog;

SELECT *
FROM Semester;

SELECT *
FROM dbo.Std;

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
(14, N'Namra',   CAST(0x90C30000 AS SmallDateTime), 3, N'03133456789', NULL, NULL, NULL, 2),
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
