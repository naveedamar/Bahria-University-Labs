# ⚡ DSA Lab 12 – Hashing

### 🎯 Objectives

By completing this lab, students will be able to:

- **Implement Hash Tables** using different hashing strategies.  
- **Apply Hashing Functions** to map keys efficiently.  
- **Handle Collisions** using linear probing and quadratic probing.  
- **Use Hashing Concepts** to design real-world data storage systems.  

---

## 📝 Exercises

### 1. Student Records (Quadratic Probing)

You are building a system to store student records using the **last three digits of their enrollment numbers** as keys.  
The hash table size **must be a prime number**, ensuring better distribution of keys.

To handle collisions effectively, the system will use **Quadratic Probing**.

#### **Tasks**
- Create a **Hash Table** of prime size.  
- Insert **at least 25 enrollment numbers**.  
- Implement the following operations:  
  - **Put()** – Insert an enrollment number  
  - **Get()** – Search an enrollment number  
  - **Delete()** – Remove an enrollment number  
- Use **quadratic probing** whenever a collision occurs.

#### **Goal**
To understand how hashing stores large datasets efficiently and how quadratic probing minimizes clustering.

---

### 2. Character Codes Hashing (Linear Probing)

You are given special character codes:  
A = 1, B = 2, … , Z = 26.

Using a hash table of **11 positions**, apply the following function:

**h(identifier) = average % 11**  
where *average* = average of the codes of the **first** and **last** characters.

Collisions are handled using **Linear Probing**.

#### **Tasks**
- Insert the following identifiers in order:  
  BETA, RATE, FREQ, ALPHA, MEAN, SUM, NUM, BAR, WAGE, PAY, KAPPA  
- Build the hash table step-by-step.  
- Use **linear probing** for every collision.  
- Implement a program to simulate this process.

#### **Goal**
To practice hashing with string-based keys and understand how probing resolves collisions in fixed-size tables.

---

### 3. Country’s Capital (Linear Probing)

You are working at GeoMap Solutions and must organize **country names** in a hash table of size **13** using:

**h(country_name) = country_name.length() % 13**

Collisions will be resolved using **Linear Probing**.

#### **Tasks**
1. Insert the following country names:  
   United States, Brazil, Japan, Germany, Pakistan, Argentina, Australia  
2. Delete a country from the hash table.  
3. Update a country using its key.  
4. Search for a country.  

#### **Goal**
To apply hashing for text-based indexing and efficient retrieval in real-world geographical databases.

