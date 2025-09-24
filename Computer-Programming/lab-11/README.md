# Lab 11 – Structures and Pointers

---

## Task 1: Company Organizational Structure
You are tasked with creating a software system to manage the organizational structure of a company. The company consists of various departments, each with a manager and multiple employees.  

Your goal is to:  
- Define structures for employees and departments  
- Implement functions to build and manage the company hierarchy  

---

## Task 2: Library Management System
You are tasked with developing a software system to manage a library of books. The system should store information about each book and its author, and allow users to search for books by title or author name.  

Requirements:  
- Define a structure named **Book** with the following members:  
  - `title` (string): The title of the book  
  - `author` (string): The author of the book  
  - `publicationYear` (int): The year the book was published  
- Accept at least 15 user inputs for books  
- Implement search functionality by title or author  
- Display search results  

---

## Task 3: Hospital Management System
You are tasked with developing a hospital management system to manage patient records efficiently.  

Requirements:  
- Define a structure named **Patient** with members for:  
  - Patient ID  
  - Name  
  - Age  
  - Medical history  
- Implement functions to:  
  - Add new patients  
  - Update existing patient information  
  - Display patient details  
- Use **pointers** to access and manipulate structure values  

---

## Task 4: Software Developer – Room Area Calculator
You are working as a software developer for a construction company. The company requires a software tool to help engineers calculate the area of different rooms in a building. Each room is represented as a rectangle.  

Structure:  
- `double length` – The length of the room  
- `double width` – The width of the room  

Functions:  
- `void inputDimensions(Room &room)` – Prompt the user to enter the length and width of the room  
- `double calculateArea(const Room &room)` – Calculate and return the area of the room  
- `void displayArea(const Room &room)` – Display the calculated area  

---
