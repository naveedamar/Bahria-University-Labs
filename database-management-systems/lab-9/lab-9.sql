--Lab 9

SELECT * FROM dbo.Semester;
SELECT * FROM dbo.Teacher;
SELECT * FROM dbo.Course;
SELECT * FROM dbo.StdCourseTeacher;
SELECT * FROM dbo.Std;
SELECT * FROM dbo.StdMarks;
select * from dbo.Exam;

--1.	Create a view to display records of Semester having SemID greater than 3 from Semester table with the following attributes:
--	Semid, Semname, StartDate
--Display all the records from view created.
CREATE VIEW greater3 AS
SELECT SemID, SemName, StartDate
FROM dbo.Semester
WHERE SemID > 3;

SELECT * FROM greater3;

--2.	Create a view named as StdInformation_vw to display record from Std table having following attributes
--StdID, StdName, StdDOB, ProgID, FirstSem
CREATE VIEW StdInformation_vw AS
SELECT StdID, StdName, StdDOB, ProgID, FirstSem
FROM dbo.Std;

SELECT * FROM StdInformation_vw;

--3.	Through view created in question 2, update the FirstSem of Sudent named Abrar from 4 to 3 and then display all the records from the same view.
UPDATE StdInformation_vw
SET FirstSem = 3
WHERE StdName = 'Abrar';

SELECT * FROM StdInformation_vw;

--4.	Create any simple view using Semester, Course and Prog table that displays the following attributes
--CourseName, CreditHrsTheory, CreditHrsLab, ProgName, SemName
CREATE VIEW stdinfo_vw AS
SELECT CourseName, CreditHrs, CreditHrsLab, ProgName, SemName
FROM dbo.Prog AS prog
INNER JOIN dbo.Course AS cour ON cour.ProgID = prog.ProgID
INNER JOIN dbo.Semester AS sem ON sem.SemID = cour.Semester;

SELECT * FROM stdinfo_vw;

--5.	Create a view which displays all the information of teacher who teaches semester 4 and 6.
CREATE VIEW teainfo_vw AS
SELECT *
FROM dbo.Teacher AS tea
INNER JOIN dbo.StdCourseTeacher AS courTea ON tea.TeacherID = courTea.TeacherID
INNER JOIN dbo.Course AS cour ON cour.CourseID = courTea.CourseID
WHERE Semester = 4 OR Semester = 6;

--6.	Create a Views that displays the sum if salaries based on the status of the teachers.
CREATE VIEW salarySumInfo AS
SELECT Job AS [JOB], SUM(BasicSalary) AS [SALARY SUM]
FROM dbo.Teacher
GROUP BY Job;

--7.	Create a view that displays the percentage obtained by all students based on their total marks.
--entering rand values in stdmarks, as it is empty
INSERT INTO StdMarks (StdID, ExamID, MarksObtained)
VALUES
-- ExamID 1–11 (Max 20)
(1, 1, 15),
(2, 3, 18),
(3, 5, 12),
(4, 8, 19),
(5, 10, 17),

-- ExamID 12–22 (Max 50)
(6, 12, 42),
(7, 15, 35),
(8, 18, 47),
(9, 20, 38),
(10, 22, 44),

-- ExamID 23–33 (Max 20)
(11, 23, 13),
(12, 26, 18),
(13, 28, 15),
(14, 30, 19),
(15, 33, 16),

-- ExamID 34–44 (Max 10)
(16, 34, 8),
(17, 36, 9),
(18, 39, 7),
(19, 42, 6),
(20, 44, 10);


CREATE VIEW marksInfo_vw AS
SELECT Std.StdID, Exam.ExamID,
    (CAST(MarksObtained AS FLOAT) / Exam.MaxMarks) * 100 AS [Percentage]
FROM dbo.StdMarks
INNER JOIN dbo.Exam ON Exam.ExamID = StdMarks.ExamID
INNER JOIN dbo.Std ON Std.StdID = StdMarks.StdID;

--8.	Create a view that calculated the GPA of students based on their percentage results calculated in the task 7
CREATE VIEW GPAInfo_vw AS
SELECT StdID, ExamID,
    ROUND(Percentage / 25, 2) AS [GPA]
FROM marksInfo_vw;

--9.	Create a view MY_VU based on the table NewTeacher which does not exists in the schema. 
--Now create the table NewTeacher from Teacher table having records of visiting Faculty. Now select all the records from the view MY_VU.
--creating NewTeacher from teachers havind visiting faculty
SELECT * INTO NewTeacher FROM dbo.Teacher
WHERE Status = 'Visiting';

CREATE VIEW MY_VU AS
SELECT *
FROM dbo.NewTeacher;

SELECT * FROM dbo.NewTeacher;



