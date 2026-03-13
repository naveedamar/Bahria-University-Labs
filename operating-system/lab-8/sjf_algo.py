class Process:
    def __init__(self, pid, service_time):
        self.pid = pid
        self.s_time = service_time
        self.w_time = 0
        self.t_time = 0

def main():
    n = int(input("Enter number of processes: "))
    pr = []

    for i in range(n):
        pid = input(f"Enter ID: ")
        service_time = int(input(f"Enter Service Time: "))
        pr.append(Process(pid, service_time))

    pr.sort(key=lambda x: x.s_time)

    pr[0].w_time = 0
    pr[0].t_time = pr[0].s_time

    total_w = 0
    total_t = pr[0].t_time

    for i in range(1, n):
        pr[i].w_time = pr[i-1].t_time
        pr[i].t_time = pr[i].w_time + pr[i].s_time
        total_w += pr[i].w_time
        total_t += pr[i].t_time

    print("\nPID\tService\tWaiting\tTotal")
    for p in pr:
        print(f"{p.pid}\t{p.s_time}\t{p.w_time}\t{p.t_time}")

    print(f"\nAverage Waiting Time: {total_w / n}")
    print(f"Average Turnaround Time: {total_t / n}")

if __name__ == "__main__":
    main()
