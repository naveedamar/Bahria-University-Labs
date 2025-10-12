# 🧮 DSA Lab 08 – Implementation of Doubly Linked List  

---

## 🎯 Objectives  

By completing this lab, students will be able to:  

* Understand and implement the **concept of doubly linked lists** in C++.  
* Perform operations such as **insertion**, **deletion**, **traversal**, and **reversal** using a doubly linked list.  
* Apply doubly linked lists in **real-world applications** like navigation systems, web browsers, and music playlists.  

---

## 📝 Exercises  

### 1. Navigation Application for Commuters  

Design a **navigation application** to help commuters travel between **Home** and **Bahria University** using a **doubly linked list**.  
Each node in the list represents a **route step** with clear navigation details.  

#### Operations:
1. Add new **route steps** (turns, directions, and distances).  
2. **Delete** the entire route when required.  
3. Navigate **forward and backward** between home and university.  
4. **Reverse the route** to travel from university back to home.  

#### Use Case:
Simulate a digital navigation tool that provides **step-by-step directions** and allows **two-way travel** between fixed destinations.  

---

### 2. Web Browser – Page Navigation System  

Implement a **web browser session manager** using a **doubly linked list** where each node stores:  
- **URL** of the page  
- **Page title**  
- Links to **previous** and **next** pages  

#### Operations:
1. **Insert** a webpage at the end of the list.  
2. **Display** all pages in both **forward** and **backward** directions.  
3. **Delete** a webpage from any position in the history.  

#### Use Case:
Model how browsers track **user history** and allow easy **forward/backward navigation** between visited sites.  

---

### 3. Music Playlist Application – “My Hit Collection”  

Create a **music playlist manager** for Sara using a **doubly linked list**.  
Each node represents a **song** with:  
- Song ID  
- Song Name  
- Singer Name  
- Year of Release  

#### Operations:
1. **Add New Songs:** Append new songs to the end of the playlist.  
2. **Play Playlist:** Traverse the playlist in both **forward** and **backward** directions.  
3. **Circular Playback:** Enable songs to loop continuously for a **seamless experience**.  
4. **Search by Year:** Display all songs released in a specified year.  
5. **Delete from Beginning:** Remove songs from the start of the playlist.  

#### Use Case:
Provide a personalized, interactive **music player system** that allows Sara to manage, play, and explore her songs efficiently.  

---

## 📂 Key Concepts  

* **Doubly Linked List** structure and operations  
* **Bidirectional traversal**  
* **Insertion** and **deletion** at various positions  
* **Reversal** and **circular linking**  
* Real-world applications in:
  - **Navigation systems**
  - **Web browsing**
  - **Music playlist management**
