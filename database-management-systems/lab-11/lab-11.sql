--Lab 11
--Objectives: To learn the Functions

--to look at the schema of the tables
SELECT * FROM Teacher;
SELECT * FROM Std;
--Examples:

--E1
Create Function CalculateAge(@dob date)
returns int
as
begin
Declare @age int
set @age = DATEDIFF(Year, @DOB, GETDATE())-
			Case when (Month(@DOB)>Month(GETDATE())) or
						(Month(@DOB)=Month(GETDATE())) AND Day(@DOB)>Day(GETDATE())
			Then 1
			Else 0
			End
return @age
end

sp_help CalculateAge
SELECT dbo.CalculateAge('2003-01-30');

--E2
Create Function fnStdBySem(@sem INT)
returns table
as
return (Select * from STD where FirstSem = @sem)

--exec func
Select * from fn_StdBySem(2)

--Lab tasks
--1.	Create an inline function without input parameters. 
--It must return the total salary of all the permanent Faculty in the Teacher table.

CREATE FUNCTION perFacSal()
RETURNS TABLE
AS
RETURN (
	SELECT SUM(BasicSalary) AS [TOTAL SALARY OF ALL PERMANENT FACULTY]
	FROM dbo.Teacher
	WHERE Status = 'Permanent'
);

SELECT * FROM dbo.perFacSal();

/*
2.	Create a scalar Function with parameters. It must take TeacherID as an input and must display Designation.
Write a SELECT Statement to display all Faculty names and their designations. 
Designation names must be displayed using Function create in second task stored function.
*/

CREATE FUNCTION facDesignation(@teacherID INT)
RETURNS VARCHAR(25)
AS
BEGIN
    DECLARE @designation VARCHAR(25)

    SET @designation = (
        SELECT Job
        FROM dbo.Teacher
        WHERE TeacherID = @teacherID
    )

    RETURN @designation
END;

SELECT TeacherID AS [ID],
	TeacherName AS [NAME],
	dbo.facDesignation(TeacherID) AS [DESIGNATION]
FROM Teacher;

/*
3.	Create a Function StdData with parameters.
It must take SEMESTER as an input and must display all Student�s names enrolled in that SEMESTER.
*/
CREATE FUNCTION StdData(@sem INT)
RETURNS TABLE
AS 
RETURN (
	SELECT StdName AS [NAME]
	FROM Std
	WHERE FirstSem = @sem
);

SELECT * FROM StdData(3);

