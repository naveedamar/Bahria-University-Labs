# 📝 Lab07: DML Queries

This lab covers **Data Manipulation Language (DML)** in SQL. The tasks focus on creating replicas of existing tables, inserting, updating, and deleting records, as well as understanding errors caused by foreign key constraints and relational dependencies.

## 📌 Objectives

* Practice SQL DML commands: `INSERT`, `UPDATE`, `DELETE`.
* Understand relational integrity and its effect on record manipulation.
* Learn how foreign key relationships restrict or enforce consistency in updates and deletions.

## 📂 Exercises Overview

1. Create replicas of `Course`, `Semester`, and `Prog` tables with/without records, and establish relationships.
2. Insert new records into the replicated `Course` table.
3. Update existing course details (e.g., rename course and adjust lab credits).
4. Delete records conditionally from `Course`.
5. Attempt to update `ProgID` and analyze constraint violation errors.
6. Insert a record with a non-existing foreign key and explain the resulting error.
7. Insert a new record into `Prog`.
8. Update a course to use the newly inserted program ID.
9. Attempt to delete the newly inserted program and note errors due to dependencies.
10. Delete a course record to resolve the dependency.
11. Reattempt program deletion and explain the successful result.
