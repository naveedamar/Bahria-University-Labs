class Process:
    def __init__(self, pid, burst_time, arrival_time):
        self.pid = pid
        self.b_time = burst_time
        self.rem_b_time = burst_time
        self.a_time = arrival_time
        self.w_time = 0
        self.t_time = 0

def main():
    n = int(input("Enter number of processes: "))
    tq = int(input("Enter time quantum: "))
    pr = []

    for i in range(n):
        pid = input(f"Enter ID: ")
        bt = int(input(f"Enter Burst Time: "))
        at = int(input(f"Enter Arrival Time: "))
        pr.append(Process(pid, bt, at))

    count = 0
    completed = 0
    
    while completed < n:
        done_in_loop = False
        for p in pr:
            if p.rem_b_time > 0:
                done_in_loop = True
                if p.rem_b_time > tq:
                    count += tq
                    p.rem_b_time -= tq
                else:
                    count += p.rem_b_time
                    p.w_time = count - p.b_time - p.a_time
                    p.t_time = count - p.a_time
                    p.rem_b_time = 0
                    completed += 1
        if not done_in_loop:
            break

    total_w = sum(p.w_time for p in pr)
    total_t = sum(p.t_time for p in pr)

    print("\nPID\tArrival\tBurst\tWaiting\tTurnaround")
    for p in pr:
        print(f"{p.pid}\t{p.a_time}\t{p.b_time}\t{p.w_time}\t{p.t_time}")

    print(f"\nAverage Waiting Time: {total_w / n}")
    print(f"Average Turnaround Time: {total_t / n}")

if __name__ == "__main__":
    main()
