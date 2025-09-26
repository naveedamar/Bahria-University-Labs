USE [Stud_Info]
GO
/****** Object:  Table [dbo].[Semester]    Script Date: 10/21/2021 17:25:21 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Semester](
      [SemID] [int] IDENTITY(1,1) NOT NULL,
      [SemName] [varchar](50) NOT NULL,
      [StartDate] [smalldatetime] NULL,
 CONSTRAINT [PK_Semester] PRIMARY KEY CLUSTERED 
(
      [SemID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
SET IDENTITY_INSERT [dbo].[Semester] ON
INSERT [dbo].[Semester] ([SemID], [SemName], [StartDate]) VALUES (1, N'Spring2020', CAST(0xAB540000 AS SmallDateTime))
INSERT [dbo].[Semester] ([SemID], [SemName], [StartDate]) VALUES (2, N'Summer2020', CAST(0xABEB0000 AS SmallDateTime))
INSERT [dbo].[Semester] ([SemID], [SemName], [StartDate]) VALUES (3, N'Fall2020', CAST(0xAC290000 AS SmallDateTime))
INSERT [dbo].[Semester] ([SemID], [SemName], [StartDate]) VALUES (4, N'Spring2021', CAST(0xACC20000 AS SmallDateTime))
INSERT [dbo].[Semester] ([SemID], [SemName], [StartDate]) VALUES (5, N'Summer2021', CAST(0xAD580000 AS SmallDateTime))
INSERT [dbo].[Semester] ([SemID], [SemName], [StartDate]) VALUES (6, N'Fall2021', CAST(0xADBE0000 AS SmallDateTime))
SET IDENTITY_INSERT [dbo].[Semester] OFF
/****** Object:  Table [dbo].[Prog]    Script Date: 10/21/2021 17:25:21 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Prog](
      [ProgID] [smallint] IDENTITY(1,1) NOT NULL,
      [ProgName] [varchar](50) NOT NULL,
      [CreditHrs] [smallint] NOT NULL,
 CONSTRAINT [PK_Prog] PRIMARY KEY CLUSTERED 
(
      [ProgID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
SET IDENTITY_INSERT [dbo].[Prog] ON
INSERT [dbo].[Prog] ([ProgID], [ProgName], [CreditHrs]) VALUES (1, N'BSCS', 140)
INSERT [dbo].[Prog] ([ProgID], [ProgName], [CreditHrs]) VALUES (2, N'BSIT', 140)
INSERT [dbo].[Prog] ([ProgID], [ProgName], [CreditHrs]) VALUES (3, N'MSCS', 36)
INSERT [dbo].[Prog] ([ProgID], [ProgName], [CreditHrs]) VALUES (4, N'MSSE', 36)
SET IDENTITY_INSERT [dbo].[Prog] OFF
/****** Object:  Table [dbo].[Teacher]    Script Date: 10/21/2021 17:25:21 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Teacher](
      [TeacherID] [int] IDENTITY(1,1) NOT NULL,
      [TeacherName] [varchar](50) NOT NULL,
      [TeacherDOB] [smalldatetime] NOT NULL,
      [TeacherDOJ] [smalldatetime] NOT NULL,
      [TeacherGender] [varchar](10) NOT NULL,
      [Status] [varchar](10) NOT NULL,
      [BasicSalary] [money] NULL,
      [HouseRent] [money] NULL,
      [Job] [varchar](50) NULL,
      [Manager] [int] NULL,
 CONSTRAINT [PK_Teacher] PRIMARY KEY CLUSTERED 
(
      [TeacherID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
SET IDENTITY_INSERT [dbo].[Teacher] ON
INSERT [dbo].[Teacher] ([TeacherID], [TeacherName], [TeacherDOB], [TeacherDOJ], [TeacherGender], [Status], [BasicSalary], [HouseRent], [Job], [Manager]) VALUES (2, N'Dr. Ahmed', CAST(0x72410000 AS SmallDateTime), CAST(0x947F0000 AS SmallDateTime), N'Male', N'Permanent', 80000.0000, 45000.0000, N'S. Lecturer', 5)
INSERT [dbo].[Teacher] ([TeacherID], [TeacherName], [TeacherDOB], [TeacherDOJ], [TeacherGender], [Status], [BasicSalary], [HouseRent], [Job], [Manager]) VALUES (3, N'Dr. Khalid', CAST(0x64840000 AS SmallDateTime), CAST(0x8CD90000 AS SmallDateTime), N'Male', N'Visiting', 100000.0000, NULL, N'J. Assist Prof', 5)
INSERT [dbo].[Teacher] ([TeacherID], [TeacherName], [TeacherDOB], [TeacherDOJ], [TeacherGender], [Status], [BasicSalary], [HouseRent], [Job], [Manager]) VALUES (4, N'Dr. Iman', CAST(0x7A600000 AS SmallDateTime), CAST(0xA94E0000 AS SmallDateTime), N'Female', N'Visiting', 100000.0000, NULL, N'J. Lecturer', 6)
INSERT [dbo].[Teacher] ([TeacherID], [TeacherName], [TeacherDOB], [TeacherDOJ], [TeacherGender], [Status], [BasicSalary], [HouseRent], [Job], [Manager]) VALUES (5, N'Dr. Safdar', CAST(0x72230000 AS SmallDateTime), CAST(0xA2A60000 AS SmallDateTime), N'Male', N'Permanent', 200000.0000, 65000.0000, N'J. Associate Prof', NULL)
INSERT [dbo].[Teacher] ([TeacherID], [TeacherName], [TeacherDOB], [TeacherDOJ], [TeacherGender], [Status], [BasicSalary], [HouseRent], [Job], [Manager]) VALUES (6, N'Dr. Sohaib', CAST(0x67AD0000 AS SmallDateTime), CAST(0x9FD00000 AS SmallDateTime), N'Male', N'Permanent', 280000.0000, 80000.0000, N'Sr. Associate Prof', NULL)
INSERT [dbo].[Teacher] ([TeacherID], [TeacherName], [TeacherDOB], [TeacherDOJ], [TeacherGender], [Status], [BasicSalary], [HouseRent], [Job], [Manager]) VALUES (7, N'Dr. Fatima', CAST(0x78750000 AS SmallDateTime), CAST(0xA87A0000 AS SmallDateTime), N'Female', N'Permanent', 225000.0000, 50000.0000, N'J. Assist Prof', 6)
SET IDENTITY_INSERT [dbo].[Teacher] OFF
/****** Object:  Table [dbo].[EvalType]    Script Date: 10/21/2021 17:25:21 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[EvalType](
      [EvalID] [smallint] NOT NULL,
      [EvalName] [varchar](50) NOT NULL,
      [EvalMarks] [int] NOT NULL,
      [ProgID] [smallint] NOT NULL,
 CONSTRAINT [PK_EvalType] PRIMARY KEY CLUSTERED 
(
      [EvalID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[EvalType] ([EvalID], [EvalName], [EvalMarks], [ProgID]) VALUES (1, N'Assignment', 20, 1)
INSERT [dbo].[EvalType] ([EvalID], [EvalName], [EvalMarks], [ProgID]) VALUES (2, N'Quiz', 10, 1)
INSERT [dbo].[EvalType] ([EvalID], [EvalName], [EvalMarks], [ProgID]) VALUES (3, N'Mid', 20, 1)
INSERT [dbo].[EvalType] ([EvalID], [EvalName], [EvalMarks], [ProgID]) VALUES (4, N'Final', 50, 1)
/****** Object:  Table [dbo].[Course]    Script Date: 10/21/2021 17:25:21 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Course](
      [CourseID] [int] IDENTITY(1,1) NOT NULL,
      [CourseName] [varchar](50) NOT NULL,
      [CreditHrsTheory] [tinyint] NOT NULL,
      [CreditHrsLab] [tinyint] NOT NULL,
      [ProgID] [smallint] NOT NULL,
      [Semester] [smallint] NOT NULL,
 CONSTRAINT [PK_Course] PRIMARY KEY CLUSTERED 
(
      [CourseID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
SET IDENTITY_INSERT [dbo].[Course] ON
INSERT [dbo].[Course] ([CourseID], [CourseName], [CreditHrsTheory], [CreditHrsLab], [ProgID], [Semester]) VALUES (1, N'Calculus - 1', 3, 0, 1, 1)
INSERT [dbo].[Course] ([CourseID], [CourseName], [CreditHrsTheory], [CreditHrsLab], [ProgID], [Semester]) VALUES (2, N'Business Communications', 2, 0, 1, 1)
INSERT [dbo].[Course] ([CourseID], [CourseName], [CreditHrsTheory], [CreditHrsLab], [ProgID], [Semester]) VALUES (3, N'Introduction To Computing', 3, 1, 1, 1)
INSERT [dbo].[Course] ([CourseID], [CourseName], [CreditHrsTheory], [CreditHrsLab], [ProgID], [Semester]) VALUES (4, N'Calculus - 2', 3, 0, 1, 2)
INSERT [dbo].[Course] ([CourseID], [CourseName], [CreditHrsTheory], [CreditHrsLab], [ProgID], [Semester]) VALUES (5, N'Pak Studies', 2, 0, 1, 2)
INSERT [dbo].[Course] ([CourseID], [CourseName], [CreditHrsTheory], [CreditHrsLab], [ProgID], [Semester]) VALUES (6, N'Programming Fundamentals', 3, 1, 1, 2)
INSERT [dbo].[Course] ([CourseID], [CourseName], [CreditHrsTheory], [CreditHrsLab], [ProgID], [Semester]) VALUES (7, N'Discrete Maths', 3, 0, 1, 3)
INSERT [dbo].[Course] ([CourseID], [CourseName], [CreditHrsTheory], [CreditHrsLab], [ProgID], [Semester]) VALUES (8, N'Data Structures', 3, 1, 1, 3)
INSERT [dbo].[Course] ([CourseID], [CourseName], [CreditHrsTheory], [CreditHrsLab], [ProgID], [Semester]) VALUES (9, N'Digital Logic', 3, 1, 1, 4)
INSERT [dbo].[Course] ([CourseID], [CourseName], [CreditHrsTheory], [CreditHrsLab], [ProgID], [Semester]) VALUES (10, N'Visual Prog', 2, 1, 1, 4)
INSERT [dbo].[Course] ([CourseID], [CourseName], [CreditHrsTheory], [CreditHrsLab], [ProgID], [Semester]) VALUES (11, N'Computer Arch and Design', 3, 1, 1, 4)
INSERT [dbo].[Course] ([CourseID], [CourseName], [CreditHrsTheory], [CreditHrsLab], [ProgID], [Semester]) VALUES (12, N'Project Management', 3, 0, 1, 4)
SET IDENTITY_INSERT [dbo].[Course] OFF
/****** Object:  Table [dbo].[Std]    Script Date: 10/21/2021 17:25:21 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Std](
      [StdID] [int] IDENTITY(1,1) NOT NULL,
      [StdName] [varchar](50) NOT NULL,
      [StdDOB] [smalldatetime] NOT NULL,
      [FirstSem] [int] NULL,
      [StdPhone] [char](15) NULL,
      [StdAddress] [varchar](50) NULL,
      [StdEmail] [varchar](50) NULL,
      [GuardianContact] [char](15) NULL,
      [ProgID] [smallint] NOT NULL,
 CONSTRAINT [PK_Std] PRIMARY KEY CLUSTERED 
(
      [StdID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
SET IDENTITY_INSERT [dbo].[Std] ON
INSERT [dbo].[Std] ([StdID], [StdName], [StdDOB], [FirstSem], [StdPhone], [StdAddress], [StdEmail], [GuardianContact], [ProgID]) VALUES (1, N'Bisma', CAST(0x8ECC0000 AS SmallDateTime), 1, N'03012345678    ', NULL, NULL, NULL, 1)
INSERT [dbo].[Std] ([StdID], [StdName], [StdDOB], [FirstSem], [StdPhone], [StdAddress], [StdEmail], [GuardianContact], [ProgID]) VALUES (2, N'Sadia', CAST(0x901A0000 AS SmallDateTime), 1, N'03112345678    ', NULL, NULL, NULL, 1)
INSERT [dbo].[Std] ([StdID], [StdName], [StdDOB], [FirstSem], [StdPhone], [StdAddress], [StdEmail], [GuardianContact], [ProgID]) VALUES (3, N'Sarah', CAST(0x90590000 AS SmallDateTime), 3, N'03023456789    ', NULL, NULL, NULL, 1)
INSERT [dbo].[Std] ([StdID], [StdName], [StdDOB], [FirstSem], [StdPhone], [StdAddress], [StdEmail], [GuardianContact], [ProgID]) VALUES (4, N'Namra', CAST(0x90C30000 AS SmallDateTime), 3, N'03123456789    ', NULL, NULL, NULL, 1)
INSERT [dbo].[Std] ([StdID], [StdName], [StdDOB], [FirstSem], [StdPhone], [StdAddress], [StdEmail], [GuardianContact], [ProgID]) VALUES (5, N'Waqar', CAST(0x8E3B0000 AS SmallDateTime), 1, N'03312345678    ', NULL, NULL, NULL, 1)
INSERT [dbo].[Std] ([StdID], [StdName], [StdDOB], [FirstSem], [StdPhone], [StdAddress], [StdEmail], [GuardianContact], [ProgID]) VALUES (6, N'Noman', CAST(0x91060000 AS SmallDateTime), 3, N'03323456789    ', NULL, NULL, NULL, 1)
INSERT [dbo].[Std] ([StdID], [StdName], [StdDOB], [FirstSem], [StdPhone], [StdAddress], [StdEmail], [GuardianContact], [ProgID]) VALUES (7, N'Abrar', CAST(0x901E0000 AS SmallDateTime), 4, N'03412345678    ', NULL, NULL, NULL, 1)
INSERT [dbo].[Std] ([StdID], [StdName], [StdDOB], [FirstSem], [StdPhone], [StdAddress], [StdEmail], [GuardianContact], [ProgID]) VALUES (8, N'Mohsin', CAST(0x906B0000 AS SmallDateTime), 4, N'03423456789    ', NULL, NULL, NULL, 1)
INSERT [dbo].[Std] ([StdID], [StdName], [StdDOB], [FirstSem], [StdPhone], [StdAddress], [StdEmail], [GuardianContact], [ProgID]) VALUES (9, N'Sikandar', CAST(0x91190000 AS SmallDateTime), 6, N'03612345678    ', NULL, NULL, NULL, 1)
INSERT [dbo].[Std] ([StdID], [StdName], [StdDOB], [FirstSem], [StdPhone], [StdAddress], [StdEmail], [GuardianContact], [ProgID]) VALUES (10, N'Javed', CAST(0x913F0000 AS SmallDateTime), 6, N'03512345678    ', NULL, NULL, NULL, 1)
SET IDENTITY_INSERT [dbo].[Std] OFF
/****** Object:  Table [dbo].[StdCourseTeacher]    Script Date: 10/21/2021 17:25:21 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[StdCourseTeacher](
      [StdID] [int] NOT NULL,
      [CourseID] [int] NOT NULL,
      [TeacherID] [int] NOT NULL,
      [SemID] [int] NOT NULL,
 CONSTRAINT [PK_StdCourseTeacher_1] PRIMARY KEY CLUSTERED 
(
      [StdID] ASC,
      [CourseID] ASC,
      [TeacherID] ASC,
      [SemID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
INSERT [dbo].[StdCourseTeacher] ([StdID], [CourseID], [TeacherID], [SemID]) VALUES (1, 9, 7, 6)
INSERT [dbo].[StdCourseTeacher] ([StdID], [CourseID], [TeacherID], [SemID]) VALUES (1, 10, 7, 6)
INSERT [dbo].[StdCourseTeacher] ([StdID], [CourseID], [TeacherID], [SemID]) VALUES (1, 11, 2, 6)
INSERT [dbo].[StdCourseTeacher] ([StdID], [CourseID], [TeacherID], [SemID]) VALUES (2, 9, 7, 6)
INSERT [dbo].[StdCourseTeacher] ([StdID], [CourseID], [TeacherID], [SemID]) VALUES (2, 10, 7, 6)
INSERT [dbo].[StdCourseTeacher] ([StdID], [CourseID], [TeacherID], [SemID]) VALUES (2, 11, 2, 6)
INSERT [dbo].[StdCourseTeacher] ([StdID], [CourseID], [TeacherID], [SemID]) VALUES (3, 7, 3, 4)
INSERT [dbo].[StdCourseTeacher] ([StdID], [CourseID], [TeacherID], [SemID]) VALUES (3, 8, 2, 4)
INSERT [dbo].[StdCourseTeacher] ([StdID], [CourseID], [TeacherID], [SemID]) VALUES (4, 7, 3, 4)
INSERT [dbo].[StdCourseTeacher] ([StdID], [CourseID], [TeacherID], [SemID]) VALUES (4, 8, 2, 4)
INSERT [dbo].[StdCourseTeacher] ([StdID], [CourseID], [TeacherID], [SemID]) VALUES (5, 9, 7, 6)
INSERT [dbo].[StdCourseTeacher] ([StdID], [CourseID], [TeacherID], [SemID]) VALUES (5, 10, 7, 6)
INSERT [dbo].[StdCourseTeacher] ([StdID], [CourseID], [TeacherID], [SemID]) VALUES (5, 11, 2, 6)
INSERT [dbo].[StdCourseTeacher] ([StdID], [CourseID], [TeacherID], [SemID]) VALUES (6, 7, 3, 4)
INSERT [dbo].[StdCourseTeacher] ([StdID], [CourseID], [TeacherID], [SemID]) VALUES (6, 8, 2, 4)
INSERT [dbo].[StdCourseTeacher] ([StdID], [CourseID], [TeacherID], [SemID]) VALUES (7, 4, 3, 3)
INSERT [dbo].[StdCourseTeacher] ([StdID], [CourseID], [TeacherID], [SemID]) VALUES (7, 5, 4, 3)
INSERT [dbo].[StdCourseTeacher] ([StdID], [CourseID], [TeacherID], [SemID]) VALUES (7, 6, 2, 3)
INSERT [dbo].[StdCourseTeacher] ([StdID], [CourseID], [TeacherID], [SemID]) VALUES (8, 4, 3, 3)
INSERT [dbo].[StdCourseTeacher] ([StdID], [CourseID], [TeacherID], [SemID]) VALUES (8, 5, 4, 3)
INSERT [dbo].[StdCourseTeacher] ([StdID], [CourseID], [TeacherID], [SemID]) VALUES (8, 6, 2, 3)
INSERT [dbo].[StdCourseTeacher] ([StdID], [CourseID], [TeacherID], [SemID]) VALUES (9, 1, 3, 6)
INSERT [dbo].[StdCourseTeacher] ([StdID], [CourseID], [TeacherID], [SemID]) VALUES (9, 2, 4, 6)
INSERT [dbo].[StdCourseTeacher] ([StdID], [CourseID], [TeacherID], [SemID]) VALUES (9, 3, 7, 6)
INSERT [dbo].[StdCourseTeacher] ([StdID], [CourseID], [TeacherID], [SemID]) VALUES (10, 1, 3, 6)
INSERT [dbo].[StdCourseTeacher] ([StdID], [CourseID], [TeacherID], [SemID]) VALUES (10, 2, 4, 6)
INSERT [dbo].[StdCourseTeacher] ([StdID], [CourseID], [TeacherID], [SemID]) VALUES (10, 3, 7, 6)
/****** Object:  Table [dbo].[Exam]    Script Date: 10/21/2021 17:25:21 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Exam](
      [ExamID] [int] IDENTITY(1,1) NOT NULL,
      [EvalID] [smallint] NOT NULL,
      [Topic] [varchar](50) NOT NULL,
      [MaxMarks] [smallint] NOT NULL,
      [SemID] [int] NOT NULL,
      [CourseID] [int] NOT NULL,
      [TeacherID] [int] NOT NULL,
 CONSTRAINT [PK_Exam] PRIMARY KEY CLUSTERED 
(
      [ExamID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
SET IDENTITY_INSERT [dbo].[Exam] ON
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (1, 3, N'Mid-Term', 20, 6, 1, 3)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (2, 3, N'Mid-Term', 20, 6, 2, 4)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (3, 3, N'Mid-Term', 20, 6, 3, 7)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (4, 3, N'Mid-Term', 20, 3, 4, 3)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (5, 3, N'Mid-Term', 20, 3, 5, 4)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (6, 3, N'Mid-Term', 20, 3, 6, 2)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (7, 3, N'Mid-Term', 20, 4, 7, 3)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (8, 3, N'Mid-Term', 20, 4, 8, 2)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (9, 3, N'Mid-Term', 20, 6, 9, 7)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (10, 3, N'Mid-Term', 20, 6, 10, 7)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (11, 3, N'Mid-Term', 20, 6, 11, 2)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (12, 4, N'Final-Term', 50, 6, 1, 3)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (13, 4, N'Final-Term', 50, 6, 2, 4)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (14, 4, N'Final-Term', 50, 6, 3, 7)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (15, 4, N'Final-Term', 50, 3, 4, 3)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (16, 4, N'Final-Term', 50, 3, 5, 4)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (17, 4, N'Final-Term', 50, 3, 6, 2)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (18, 4, N'Final-Term', 50, 4, 7, 3)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (19, 4, N'Final-Term', 50, 4, 8, 2)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (20, 4, N'Final-Term', 50, 6, 9, 7)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (21, 4, N'Final-Term', 50, 6, 10, 7)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (22, 4, N'Final-Term', 50, 6, 11, 2)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (23, 1, N'Assignment', 20, 6, 1, 3)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (24, 1, N'Assignment', 20, 6, 2, 4)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (25, 1, N'Assignment', 20, 6, 3, 7)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (26, 1, N'Assignment', 20, 3, 4, 3)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (27, 1, N'Assignment', 20, 3, 5, 4)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (28, 1, N'Assignment', 20, 3, 6, 2)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (29, 1, N'Assignment', 20, 4, 7, 3)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (30, 1, N'Assignment', 20, 4, 8, 2)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (31, 1, N'Assignment', 20, 6, 9, 7)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (32, 1, N'Assignment', 20, 6, 10, 7)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (33, 1, N'Assignment', 20, 6, 11, 2)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (34, 2, N'Quiz', 10, 6, 1, 3)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (35, 2, N'Quiz', 10, 6, 2, 4)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (36, 2, N'Quiz', 10, 6, 3, 7)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (37, 2, N'Quiz', 10, 3, 4, 3)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (38, 2, N'Quiz', 10, 3, 5, 4)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (39, 2, N'Quiz', 10, 3, 6, 2)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (40, 2, N'Quiz', 10, 4, 7, 3)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (41, 2, N'Quiz', 10, 4, 8, 2)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (42, 2, N'Quiz', 10, 6, 9, 7)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (43, 2, N'Quiz', 10, 6, 10, 7)
INSERT [dbo].[Exam] ([ExamID], [EvalID], [Topic], [MaxMarks], [SemID], [CourseID], [TeacherID]) VALUES (44, 2, N'Quiz', 10, 6, 11, 2)
SET IDENTITY_INSERT [dbo].[Exam] OFF
/****** Object:  Table [dbo].[StdMarks]    Script Date: 10/21/2021 17:25:21 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[StdMarks](
      [StdID] [int] NOT NULL,
      [ExamID] [int] NOT NULL,
      [MarksObtained] [smallint] NOT NULL,
 CONSTRAINT [PK_StdMarks] PRIMARY KEY CLUSTERED 
(
      [StdID] ASC,
      [ExamID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Default [DF_StdMarks_MarksObtained]    Script Date: 10/21/2021 17:25:21 ******/
ALTER TABLE [dbo].[StdMarks] ADD  CONSTRAINT [DF_StdMarks_MarksObtained]  DEFAULT ((0)) FOR [MarksObtained]
GO
/****** Object:  Default [DF_Teacher_BasicSalary]    Script Date: 10/21/2021 17:25:21 ******/
ALTER TABLE [dbo].[Teacher] ADD  CONSTRAINT [DF_Teacher_BasicSalary]  DEFAULT ((0)) FOR [BasicSalary]
GO
/****** Object:  ForeignKey [FK_Course_Prog]    Script Date: 10/21/2021 17:25:21 ******/
ALTER TABLE [dbo].[Course]  WITH CHECK ADD  CONSTRAINT [FK_Course_Prog] FOREIGN KEY([ProgID])
REFERENCES [dbo].[Prog] ([ProgID])
GO
ALTER TABLE [dbo].[Course] CHECK CONSTRAINT [FK_Course_Prog]
GO
/****** Object:  ForeignKey [FK_EvalType_Prog]    Script Date: 10/21/2021 17:25:21 ******/
ALTER TABLE [dbo].[EvalType]  WITH CHECK ADD  CONSTRAINT [FK_EvalType_Prog] FOREIGN KEY([ProgID])
REFERENCES [dbo].[Prog] ([ProgID])
GO
ALTER TABLE [dbo].[EvalType] CHECK CONSTRAINT [FK_EvalType_Prog]
GO
/****** Object:  ForeignKey [FK_Exam_Course]    Script Date: 10/21/2021 17:25:21 ******/
ALTER TABLE [dbo].[Exam]  WITH CHECK ADD  CONSTRAINT [FK_Exam_Course] FOREIGN KEY([CourseID])
REFERENCES [dbo].[Course] ([CourseID])
GO
ALTER TABLE [dbo].[Exam] CHECK CONSTRAINT [FK_Exam_Course]
GO
/****** Object:  ForeignKey [FK_Exam_Semester]    Script Date: 10/21/2021 17:25:21 ******/
ALTER TABLE [dbo].[Exam]  WITH CHECK ADD  CONSTRAINT [FK_Exam_Semester] FOREIGN KEY([SemID])
REFERENCES [dbo].[Semester] ([SemID])
GO
ALTER TABLE [dbo].[Exam] CHECK CONSTRAINT [FK_Exam_Semester]
GO
/****** Object:  ForeignKey [FK_Exam_Teacher]    Script Date: 10/21/2021 17:25:21 ******/
ALTER TABLE [dbo].[Exam]  WITH CHECK ADD  CONSTRAINT [FK_Exam_Teacher] FOREIGN KEY([TeacherID])
REFERENCES [dbo].[Teacher] ([TeacherID])
GO
ALTER TABLE [dbo].[Exam] CHECK CONSTRAINT [FK_Exam_Teacher]
GO
/****** Object:  ForeignKey [FK_Std_Prog]    Script Date: 10/21/2021 17:25:21 ******/
ALTER TABLE [dbo].[Std]  WITH CHECK ADD  CONSTRAINT [FK_Std_Prog] FOREIGN KEY([ProgID])
REFERENCES [dbo].[Prog] ([ProgID])
GO
ALTER TABLE [dbo].[Std] CHECK CONSTRAINT [FK_Std_Prog]
GO
/****** Object:  ForeignKey [FK_StdCourseTeacher_Course]    Script Date: 10/21/2021 17:25:21 ******/
ALTER TABLE [dbo].[StdCourseTeacher]  WITH CHECK ADD  CONSTRAINT [FK_StdCourseTeacher_Course] FOREIGN KEY([CourseID])
REFERENCES [dbo].[Course] ([CourseID])
GO
ALTER TABLE [dbo].[StdCourseTeacher] CHECK CONSTRAINT [FK_StdCourseTeacher_Course]
GO
/****** Object:  ForeignKey [FK_StdCourseTeacher_Semester]    Script Date: 10/21/2021 17:25:21 ******/
ALTER TABLE [dbo].[StdCourseTeacher]  WITH CHECK ADD  CONSTRAINT [FK_StdCourseTeacher_Semester] FOREIGN KEY([SemID])
REFERENCES [dbo].[Semester] ([SemID])
GO
ALTER TABLE [dbo].[StdCourseTeacher] CHECK CONSTRAINT [FK_StdCourseTeacher_Semester]
GO
/****** Object:  ForeignKey [FK_StdCourseTeacher_Std]    Script Date: 10/21/2021 17:25:21 ******/
ALTER TABLE [dbo].[StdCourseTeacher]  WITH CHECK ADD  CONSTRAINT [FK_StdCourseTeacher_Std] FOREIGN KEY([StdID])
REFERENCES [dbo].[Std] ([StdID])
GO
ALTER TABLE [dbo].[StdCourseTeacher] CHECK CONSTRAINT [FK_StdCourseTeacher_Std]
GO
/****** Object:  ForeignKey [FK_StdCourseTeacher_Teacher]    Script Date: 10/21/2021 17:25:21 ******/
ALTER TABLE [dbo].[StdCourseTeacher]  WITH CHECK ADD  CONSTRAINT [FK_StdCourseTeacher_Teacher] FOREIGN KEY([TeacherID])
REFERENCES [dbo].[Teacher] ([TeacherID])
GO
ALTER TABLE [dbo].[StdCourseTeacher] CHECK CONSTRAINT [FK_StdCourseTeacher_Teacher]
GO
/****** Object:  ForeignKey [FK_StdMarks_Exam]    Script Date: 10/21/2021 17:25:21 ******/
ALTER TABLE [dbo].[StdMarks]  WITH CHECK ADD  CONSTRAINT [FK_StdMarks_Exam] FOREIGN KEY([ExamID])
REFERENCES [dbo].[Exam] ([ExamID])
GO
ALTER TABLE [dbo].[StdMarks] CHECK CONSTRAINT [FK_StdMarks_Exam]
GO
/****** Object:  ForeignKey [FK_StdMarks_Std]    Script Date: 10/21/2021 17:25:21 ******/
ALTER TABLE [dbo].[StdMarks]  WITH CHECK ADD  CONSTRAINT [FK_StdMarks_Std] FOREIGN KEY([StdID])
REFERENCES [dbo].[Std] ([StdID])
GO
ALTER TABLE [dbo].[StdMarks] CHECK CONSTRAINT [FK_StdMarks_Std]
GO