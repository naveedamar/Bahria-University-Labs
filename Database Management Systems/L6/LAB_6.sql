--LAB 6
USE [stud-data];
SELECT DB_NAME();

--T1
SELECT *
INTO newTeacher
FROM Teacher;

SELECT *
FROM Teacher;

SELECT * 
FROM newTeacher;

--T2
SELECT *
FROM Prog;
SELECT *
FROM Std;

--BSCS HAS PROGID OF 1
SELECT *
INTO newStd
FROM Std
WHERE ProgID = 1;

SELECT *
FROM newStd;

--T3
SELECT *
FROM newTeacher;

ALTER TABLE newTeacher
ADD address VARCHAR(255) NULL;

SELECT *
FROM newTeacher;

--T4
SELECT *
FROM newTeacher;

ALTER TABLE newTeacher
drop column address;

SELECT * FROM newTeacher;

--T5
ALTER TABLE newTeacher
ADD houseNo VARCHAR(5) NOT NULL DEFAULT '0',
    streetNo TINYINT NULL,
    area VARCHAR(50) NOT NULL DEFAULT 'Unknown',
    city VARCHAR(50) NOT NULL DEFAULT 'Unknown';

SELECT * FROM newTeacher;

--T6
ALTER TABLE newTeacher
ALTER COLUMN houseNo NUMERIC(4,2) NOT NULL;

ALTER TABLE newTeacher
DROP CONSTRAINT DF__newTeache__house__5CD6CB2B;

ALTER TABLE newTeacher
ADD CONSTRAINT DF_newTeacher_houseNo DEFAULT(0.0) FOR houseNO;

SELECT * FROM newTeacher;

--T7
-- FACULTY 
CREATE TABLE Faculty (
    FacultyID INT PRIMARY KEY,
    FacultyName VARCHAR(25) NOT NULL
);

-- COURSE TABLE ALREADY EXITS
SELECT * FROM Course;


-- CLASS 
CREATE TABLE Class (
    ClassID INT PRIMARY KEY,
    CourseID INT,
    SectionNo INT,
    Semester VARCHAR(10),
    FOREIGN KEY (CourseID) REFERENCES Course(CourseID)
);

-- STUDENT
CREATE TABLE Student (
    StudentID INT PRIMARY KEY,
    StudentName VARCHAR(25) NOT NULL,
    FacultyID INT,
    FOREIGN KEY (FacultyID) REFERENCES Faculty(FacultyID)
);



--T8
SELECT * FROM Student;

ALTER TABLE Student
ADD Class VARCHAR(10),
    Phone VARCHAR(15);

SELECT * FROM Student;

--T9
ALTER TABLE Student
ALTER COLUMN StudentName VARCHAR(20) NOT NULL;

--T10
DELETE FROM Student;

--T11
SELECT name, parent_object_id, referenced_object_id
FROM sys.foreign_keys;

ALTER TABLE Student
DROP CONSTRAINT FK__Student__Faculty__6754599E;

ALTER TABLE Class
DROP CONSTRAINT FK__Class__CourseID__6477ECF3;


DROP TABLE Faculty;
DROP TABLE Course;

--T12
CREATE TABLE Department (
    DeptNO INT PRIMARY KEY,
    DName VARCHAR(10),
    LOC VARCHAR(10),
);

--T13
CREATE TABLE Employee (
    EmpNO SMALLINT PRIMARY KEY,
    EName VARCHAR(10),
    SAL INT,
    DeptNO INT,

    FOREIGN KEY (DeptNO) REFERENCES Department(DeptNO)
);

--T14
ALTER TABLE Employee
ADD CONSTRAINT CK_Employee_EName_UPPER
CHECK (EName = UPPER(EName));

--T15
ALTER TABLE Department
ADD CONSTRAINT CK_Department_DName_NotEmpty
CHECK (DName IS NOT NULL AND DName <> '');

--T16
ALTER TABLE Employee
ADD CONSTRAINT UQ_Employee_SAL UNIQUE (SAL);

--T17
ALTER TABLE Department  
ADD CONSTRAINT UQ_Department_DName UNIQUE (DName);
