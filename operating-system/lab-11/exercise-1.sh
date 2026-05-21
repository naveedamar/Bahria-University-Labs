#!/usr/bin/env python3

# implements the Banker's algorithm to check for a safe state in resource allocation.
def is_safe_state(processes, available, max_demand, allocation):
    n = len(processes)
    m = len(available)
    
    need = [[0] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            need[i][j] = max_demand[i][j] - allocation[i][j]
    
    work = available.copy()
    finish = [False] * n
    safe_seq = []
    
    count = 0
    while count < n:
        found = False
        for i in range(n):
            if not finish[i]:
                can_execute = True
                for j in range(m):
                    if need[i][j] > work[j]:
                        can_execute = False
                        break
                
                if can_execute:
                    for j in range(m):
                        work[j] += allocation[i][j]
                    safe_seq.append(processes[i])
                    finish[i] = True
                    found = True
                    count += 1
        
        if not found:
            return False, []
            
    return True, safe_seq

def main():
    processes = ["P0", "P1", "P2", "P3", "P4"]
    
    available = [3, 3, 2]
    
    max_demand = [
        [7, 5, 3],
        [3, 2, 2],
        [9, 0, 2],
        [2, 2, 2],
        [4, 3, 3]
    ]
    
    allocation = [
        [0, 1, 0],
        [2, 0, 0],
        [3, 0, 2],
        [2, 1, 1],
        [0, 0, 2]
    ]
    
    safe, sequence = is_safe_state(processes, available, max_demand, allocation)
    
    if safe:
        print("System is in a Safe State.")
        print("Safe Sequence is:", " -> ".join(sequence))
    else:
        print("System is NOT in a Safe State. Deadlock may occur.")

if __name__ == "__main__":
    main()