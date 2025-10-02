/*
Objectives:
	To learn the Data Manipulation Language (DML)
*/

--Tasks
/*
1.	Create a new table Course replica of Course table with no records in it.
Create a new table Semester replica of Semester table with all records in it.
Create a new table Prog replica of Prog table with all the records in it. 
Create a primary Foreign Key relationship between the newly created Course, Prog and Semester tables.
*/

--creating replicas
SELECT *
INTO newCourse
FROM Course
WHERE 1 = 0;

SELECT *
INTO newSemester
FROM Semester;

SELECT *
INTO newProg
FROM Prog;

--first seeing the primary key of table and then adding constraints to new tables

--EXEC sp_help 'Course';
ALTER TABLE	newCourse
ADD CONSTRAINT PK_newCourse PRIMARY	KEY(courseID);

--EXEC sp_help 'Semester';
ALTER TABLE	newSemester
ADD CONSTRAINT PK_newSemester PRIMARY KEY(SemID);

--EXEC sp_help 'Prog';
ALTER TABLE	newProg
ADD CONSTRAINT PK_newProg PRIMARY KEY(ProgID);

/*
2.	Insert following records into Course using following values:
CourseName = ‘DBMS’, CreditHrsTheory = 3, CreditHrsLab = 1, ProgID=1, SemID=4.
CourseName = ‘OOP’, CreditHrsTheory = 3, CreditHrsLab = 1, ProgID=2, SemID=3.
CourseName = ‘NLP’, CreditHrsTheory = 3, CreditHrsLab = 0, ProgID=2, SemID=5.
CourseName = ‘DSA’, CreditHrsTheory = 3, CreditHrsLab = 0, ProgID=2, SemID=5.
*/

--seeing the newCourse table structure 
--EXEC sp_help 'newCourse';
INSERT INTO newCourse(CourseName,CreditHrsTheory, CreditHrsLab, ProgID, Semester)
VALUES 
	('DBMS', 3, 1, 1, 4),
	('OOP', 3, 1, 2, 3),
	('NLP', 3, 0, 2, 5),
	('DSA', 3, 0, 2, 5);

/*
3.	Change the record inserted in question 2 from CourseName ‘NLP to ‘AI’ and CreditHrsLabs to 1
*/
UPDATE newCourse
SET 
	CourseName = 'AI',
	CreditHrsLab = 1
WHERE CourseName = 'NLP';

/*
4.	Remove all the records from Course table having CreditHrsLab = 0
*/
DELETE FROM newCourse
WHERE CreditHrsLab = 0;

/*
5.	Try to update the table Prog and change the value of ProgID from 4 to 10. Find the error and give the reason for the error
*/
UPDATE newProg
SET ProgID = 10
WHERE ProgID = 4;

/*
6.	Insert a new record into Course using following values:
CourseName = ‘CP’, CreditHrsTheory = 3, CreditHrsLab = 1, ProgID=10, SemID=3. Find the error and give the reason for the error.
*/
INSERT INTO Course(CourseName, CreditHrsTheory, CreditHrsLab, ProgID, Semester)
VALUES ('CP', 3, 1, 10, 3);
--shows error becuase of fk depandance (no such prog that has ID = 10)

/*
7.	Insert A new record in Prog table using following values:
ProgName=’MSIT’, CreditHrs=36
*/
INSERT INTO newProg(ProgName, CreditHrs)
VALUES ('MSIT', 36);

/*
8.	Change the record in Course table and set the ProgID for the CourseName=’AI’ as the ProgID of record added in task 7.
*/
UPDATE newCourse
SET ProgID = (
	SELECT ProgID
	FROM newProg
	WHERE ProgName = 'MSIT'
	)
WHERE CourseName = 'AI';

/*
9.	Delete the record from Prog table that was added in task 7. Note the error and give reason for the error.
*/
DELETE FROM newProg
WHERE ProgName = 'MSIT';

/*
10.	Delete the record of ‘AI’ course from the Course table
*/
DELETE FROM newCourse
WHERE CourseName = 'AI';

/*
11.	Repeat the task 9 and note the results and see what happens and provide appropriate reasoning for the results.
*/
DELETE FROM newProg
WHERE ProgName = 'MSIT';
