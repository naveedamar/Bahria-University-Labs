# OS Lab 08: CPU Scheduling Algorithms

Implementation and analysis of three core CPU scheduling algorithms in Python.

## 📝 Problem Statements

### Task 1: First-Come, First-Served (FCFS)
Executes processes in the order of their arrival.
* **Logic:** Non-preemptive.
* **Goal:** Calculate Waiting Time and Turnaround Time for each process.



### Task 2: Shortest Job First (SJF)
Executes the process with the smallest service time first.
* **Logic:** Non-preemptive.
* **Goal:** Minimize average waiting time by sorting processes by burst time.



### Task 3: Round Robin (RR)
Allocates a fixed time unit (Time Quantum) to each process.
* **Logic:** Preemptive.
* **Goal:** Ensure fair CPU sharing by cycling through processes until completion.

## Evaluation Formulas
* **Waiting Time:** Total time a process spends waiting in the ready queue.
* **Turnaround Time:** Total time from process arrival to completion.
* **Averages:** Sum of all times divided by the total number of processes.

---

## 🛠️ Requirements
* **Environment:** Ubuntu (Linux)
* **Language:** Python 3.x