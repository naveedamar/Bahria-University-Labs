--Objectives: To learn the Triggers
USE Stud_Info
GO;

/*
1.Create a new table which is the replica of Teacher table without records. 
Now write a trigger on Teacher table so that whenever any DML operation is performed on EMP, 
original record of the Teacher table must be maintained in the new table before getting changed in it.
*/

--Replica of Teacher table created with NewTeacher name; without any records
SELECT *
INTO NewTeacher
FROM Teacher
WHERE 1 = 0;

--Creating Trigger
CREATE TRIGGER teacher_changed
ON Teacher
AFTER INSERT, UPDATE, DELETE
AS
BEGIN
    SET NOCOUNT ON;
    
    SET IDENTITY_INSERT NewTeacher ON;
    
    INSERT INTO NewTeacher (
        TeacherID, TeacherName, TeacherDOB, TeacherDOJ, 
        TeacherGender, Status, BasicSalary, HouseRent, Job, Manager
    )
    SELECT 
        TeacherID, TeacherName, TeacherDOB, TeacherDOJ, 
        TeacherGender, Status, BasicSalary, HouseRent, Job, Manager
    FROM deleted;
    
    SET IDENTITY_INSERT NewTeacher OFF;
END

--checking trigger
INSERT INTO Teacher (
    TeacherName, 
    TeacherDOB, 
    TeacherDOJ, 
    TeacherGender, 
    Status, 
    BasicSalary, 
    HouseRent, 
    Job, 
    Manager
)
VALUES (
    'Dr. Shahid',          
    '1985-05-15',           
    '2020-08-01',           
    'Male',                 
    'Visiting',               
    50000.00,               
    15000.00,              
    'Professor',           
    NULL                   
);

DELETE FROM Teacher 
WHERE TeacherID = 8;

SELECT * FROM NewTeacher;

/*
2.Create a trigger on Teacher table which stops any person from INSERT or UPDATE of the record 
if the new job of the affected record is ‘Sr. Lecturer’ and new salary is less than 45000.
*/

CREATE TRIGGER teacher_criteria
ON Teacher
AFTER INSERT, UPDATE
AS
BEGIN
    SET NOCOUNT ON;

    IF EXISTS (
        SELECT 1
        FROM inserted
        WHERE Job = 'Sr. Lecturer'
          AND BasicSalary < 45000
    )
    BEGIN
        RAISERROR('Sr. Lecturer must have salary >= 45000. Operation cancelled.', 16, 1);
        ROLLBACK TRANSACTION;
    END
END;

--checking
INSERT INTO Teacher (
    TeacherName, 
    TeacherDOB, 
    TeacherDOJ, 
    TeacherGender, 
    Status, 
    BasicSalary, 
    HouseRent, 
    Job, 
    Manager
)
VALUES (
    'Dr. Shahid',          
    '1985-05-15',           
    '2020-08-01',           
    'Male',                 
    'Visiting',               
    5000.00,               
    15000.00,              
    'Sr. Lecturer',           
    NULL                   
);
