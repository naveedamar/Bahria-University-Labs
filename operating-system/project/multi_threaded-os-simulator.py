# lab project where I am simulating an OS with multi-threading, scheduling, memory management, and deadlock detection.
import threading
import time
import random
import sys

C_RESET = '\033[0m'
C_CYAN = '\033[96m'
C_BLUE = '\033[94m'
C_MAGENTA = '\033[95m'
C_GREEN = '\033[92m'
C_RED = '\033[91m'
C_YELLOW = '\033[93m'

TOTAL_MEMORY = 256
FRAME_SIZE = 64
NUM_FRAMES = TOTAL_MEMORY // FRAME_SIZE
NUM_RES = 3


class Process:
    def __init__(self, pid, arr, brst, mem, prio):
        self.pid = pid
        self.arrivalTime = arr
        self.burstTime = brst
        self.remainingTime = brst
        self.priority = prio
        self.memoryRequired = mem
        self.maxNeed = [random.randint(1, 3) for _ in range(NUM_RES)]
        self.allocated = [0] * NUM_RES
        self.need = list(self.maxNeed)
        self.state = "NEW"
        self.memAllocated = False
        self.wait_time = 0
        self.completion_time = 0


class OSSimulator:
    def __init__(self, scheduler_choice):
        self.totalRes = [5, 5, 5]
        self.availableRes = list(self.totalRes)
        self.frameOwner = [-1] * NUM_FRAMES
        self.scheduler_choice = scheduler_choice
        self.rr_ptr = 0
        self.FCFS, self.SJF, self.RR, self.PRIORITY = 0, 1, 2, 3
        self.timeline = []

    def select_fcfs(self, rq):
        return rq[0] if rq else -1

    def select_sjf(self, rq, procs):
        if not rq: return -1
        best = rq[0]
        best_t = procs[best].remainingTime
        for idx in rq:
            if procs[idx].remainingTime < best_t:
                best_t = procs[idx].remainingTime
                best = idx
        return best

    def select_rr(self, rq):
        if not rq: return -1
        if self.rr_ptr >= len(rq):
            self.rr_ptr = 0
        idx = rq[self.rr_ptr]
        self.rr_ptr = (self.rr_ptr + 1) % len(rq)
        return idx

    def select_priority(self, rq, procs):
        if not rq: return -1
        best_idx = rq[0]
        best_prio = procs[best_idx].priority
        for idx in rq:
            if procs[idx].priority < best_prio:
                best_prio = procs[idx].priority
                best_idx = idx
        return best_idx

    def choose_scheduler(self, rq, procs):
        if self.scheduler_choice != -1:
            return self.scheduler_choice
        if not rq: return self.FCFS
        for idx in rq:
            if procs[idx].priority == 1:
                return self.PRIORITY
        if len(rq) > 5: return self.RR
        avg = sum(procs[idx].remainingTime for idx in rq) / len(rq)
        return self.SJF if avg <= 5 else self.FCFS

    def allocate_memory(self, p):
        frames_needed = (p.memoryRequired + FRAME_SIZE - 1) // FRAME_SIZE
        free_frames = [i for i, owner in enumerate(self.frameOwner) if owner == -1]
        if len(free_frames) < frames_needed:
            return False
        for f in free_frames[:frames_needed]:
            self.frameOwner[f] = p.pid
        return True

    def free_memory(self, p):
        for i in range(NUM_FRAMES):
            if self.frameOwner[i] == p.pid:
                self.frameOwner[i] = -1

    def is_safe(self, procs):
        work = list(self.availableRes)
        finish = [False] * len(procs)
        changed = True
        while changed:
            changed = False
            for i, p in enumerate(procs):
                if not finish[i] and p.state != "FINISHED":
                    if all(p.need[r] <= work[r] for r in range(NUM_RES)):
                        for r in range(NUM_RES):
                            work[r] += p.allocated[r]
                        finish[i] = True
                        changed = True
        for i, p in enumerate(procs):
            if p.state != "FINISHED" and not finish[i]:
                return False
        return True

    def detect_deadlock(self, procs):
        if self.is_safe(procs): return
        print(f"\n{C_RED}******** DEADLOCK DETECTED ********{C_RESET}")
        victim, worst_rem = -1, -1
        for i, p in enumerate(procs):
            if p.state not in ["FINISHED", "NEW"] and p.remainingTime > worst_rem:
                worst_rem = p.remainingTime
                victim = i
        if victim == -1: return
        print(f"{C_RED}Aborting P{procs[victim].pid} to recover.{C_RESET}")
        for r in range(NUM_RES):
            self.availableRes[r] += procs[victim].allocated[r]
            procs[victim].allocated[r] = 0
            procs[victim].need[r] = 0
        procs[victim].state = "FINISHED"

    def print_gantt_chart(self):
        if not self.timeline:
            return

        print(f"\n{C_CYAN}" + "=" * 70)
        print("                        CPU GANTT CHART")
        print("=" * 70 + f"{C_RESET}")

        chunks = []
        current_chunk = []
        current_len = 0

        for entry in self.timeline:
            width = max(len(entry[0]) + 2, 5)
            if current_len + width > 65:
                chunks.append(current_chunk)
                current_chunk = []
                current_len = 0
            current_chunk.append(entry)
            current_len += width + 1

        if current_chunk:
            chunks.append(current_chunk)

        for chunk in chunks:
            top = "+"
            mid = "|"
            bot = "+"
            times = f"{chunk[0][1]:02d}"

            for proc, start, end in chunk:
                width = max(len(proc) + 2, 5)
                top += "-" * width + "+"
                mid += f" {proc.center(width - 2)} |"
                bot += "-" * width + "+"
                times += f"{end:>{width + 1}}"

            print(top)
            print(mid)
            print(bot)
            print(times)
            print()

    def print_metrics(self, procs):
        print(f"{C_CYAN}" + "=" * 70)
        print("                     PERFORMANCE METRICS")
        print("=" * 70)
        print(f"{'PID':<6} | {'Arrival':<8} | {'Burst':<6} | {'Completion':<12} | {'Turnaround':<12} | {'Waiting':<8}")
        print("-" * 70 + f"{C_RESET}")

        total_tat = 0
        total_wt = 0

        for p in procs:
            tat = p.completion_time - p.arrivalTime
            wt = tat - p.burstTime
            total_tat += tat
            total_wt += wt
            print(
                f"P{p.pid:<5} | {p.arrivalTime:<8} | {p.burstTime:<6} | {p.completion_time:<12} | {tat:<12} | {wt:<8}")

        print(f"{C_CYAN}" + "-" * 70)
        print(f"Average Turnaround Time : {total_tat / len(procs):.2f} ticks")
        print(f"Average Waiting Time    : {total_wt / len(procs):.2f} ticks")
        print("=" * 70 + f"{C_RESET}\n")

    def run(self, procs):
        n = len(procs)
        ready_queue = []
        finished = 0
        time_tick = 0

        current_running = None
        slice_start = 0

        print(f"\n{C_CYAN}" + "=" * 70)
        print("                 OS SIMULATION EXECUTION LOG")
        print("=" * 70 + f"{C_RESET}")

        while finished < n:
            for i, p in enumerate(procs):
                if p.state == "NEW" and p.arrivalTime <= time_tick:
                    p.state = "READY"
                    ready_queue.append(i)
                elif p.state == "MEM_WAIT":
                    if self.allocate_memory(p):
                        p.state = "READY"
                        p.memAllocated = True
                        ready_queue.append(i)

            if not ready_queue:
                active_proc = "IDLE"
                if active_proc != current_running:
                    if current_running is not None:
                        self.timeline.append((current_running, slice_start, time_tick))
                    current_running = active_proc
                    slice_start = time_tick

                print(f"{C_YELLOW}t={time_tick:02d} : CPU IDLE{C_RESET}")
                time_tick += 1
                time.sleep(0.02)
                continue

            st = self.choose_scheduler(ready_queue, procs)
            if st == self.FCFS:
                idx = self.select_fcfs(ready_queue)
            elif st == self.SJF:
                idx = self.select_sjf(ready_queue, procs)
            elif st == self.RR:
                idx = self.select_rr(ready_queue)
            else:
                idx = self.select_priority(ready_queue, procs)

            p = procs[idx]

            if not p.memAllocated:
                if not self.allocate_memory(p):
                    print(f"{C_MAGENTA}t={time_tick:02d} : P{p.pid} waiting for memory frames{C_RESET}")
                    p.state = "MEM_WAIT"
                    ready_queue.remove(idx)
                    time_tick += 1
                    time.sleep(0.02)
                    continue
                p.memAllocated = True
                print(f"{C_MAGENTA}t={time_tick:02d} : Memory allocated to P{p.pid}{C_RESET}")

            active_proc = f"P{p.pid}"
            if active_proc != current_running:
                if current_running is not None:
                    self.timeline.append((current_running, slice_start, time_tick))
                current_running = active_proc
                slice_start = time_tick

            p.state = "RUNNING"
            sched_name = {self.FCFS: "FCFS", self.SJF: "SJF", self.RR: "RR", self.PRIORITY: "PRIO"}.get(st)
            print(f"{C_BLUE}t={time_tick:02d} : [{sched_name}] Running P{p.pid} (Rem: {p.remainingTime}){C_RESET}")

            p.remainingTime -= 1

            if p.remainingTime <= 0:
                p.state = "FINISHED"
                p.completion_time = time_tick + 1
                finished += 1
                self.free_memory(p)
                ready_queue.remove(idx)
                print(f"{C_GREEN}t={time_tick + 1:02d} : P{p.pid} FINISHED and memory freed{C_RESET}\n")
            else:
                p.state = "READY"

            self.detect_deadlock(procs)
            time_tick += 1
            time.sleep(0.02)

        if current_running is not None:
            self.timeline.append((current_running, slice_start, time_tick))

        self.print_gantt_chart()
        self.print_metrics(procs)


sharedCounter = 0
counterMutex = threading.Lock()


def worker_no_lock(loops):
    global sharedCounter
    for _ in range(loops): sharedCounter += 1


def worker_with_lock(loops):
    global sharedCounter
    for _ in range(loops):
        with counterMutex: sharedCounter += 1


def sync_demo():
    global sharedCounter
    print(f"\n{C_CYAN}" + "-" * 70)
    print("           RACE CONDITION vs MUTEX SYNCHRONIZATION")
    print("-" * 70 + f"{C_RESET}")

    sharedCounter = 0
    t1 = threading.Thread(target=worker_no_lock, args=(100000,))
    t2 = threading.Thread(target=worker_no_lock, args=(100000,))
    t1.start();
    t2.start()
    t1.join();
    t2.join()
    print(f"{C_RED}[No Lock] Expected 200000, Result: {sharedCounter} (Data Corrupted){C_RESET}")

    sharedCounter = 0
    t3 = threading.Thread(target=worker_with_lock, args=(100000,))
    t4 = threading.Thread(target=worker_with_lock, args=(100000,))
    t3.start();
    t4.start()
    t3.join();
    t4.join()
    print(f"{C_GREEN}[Mutex]   Expected 200000, Result: {sharedCounter} (Data Safe){C_RESET}")
    print(f"{C_CYAN}" + "-" * 70 + f"{C_RESET}\n")


def main():
    try:
        n = int(input("Enter number of processes: "))
        mode = int(input("Choose input mode: 1) Manual 2) Random: "))

        print("0 = Auto, 1 = FCFS, 2 = SJF, 3 = RR, 4 = PRIORITY")
        schChoice = int(input("Enter scheduler choice: "))

        override = schChoice - 1 if 1 <= schChoice <= 4 else -1
        sim = OSSimulator(override)
        procs = []

        if mode == 1:
            for i in range(n):
                print(f"P{i} [Arr Burst Mem Prio]: ", end="")
                arr, brst, mem, prio = map(int, input().split())
                procs.append(Process(i, arr, brst, mem, prio))
        else:
            for i in range(n):
                procs.append(Process(
                    i, random.randint(0, 5), random.randint(2, 10),
                    random.randint(64, 256), random.randint(1, 3)
                ))

        print(f"\n{C_CYAN}PROCESS CONTROL BLOCK (PCB) SNAPSHOT:")
        print("=" * 70)
        print(f"{'PID':<5}| {'Arrival':<8}| {'Burst':<8}| {'Priority':<10}| {'Memory':<10}")
        print("-" * 70 + f"{C_RESET}")
        for p in procs:
            print(f"P{p.pid:<4}| {p.arrivalTime:<8}| {p.burstTime:<8}| {p.priority:<10}| {p.memoryRequired:<10}")
        print(f"{C_CYAN}" + "=" * 70 + f"{C_RESET}")

        sim.run(procs)
        sync_demo()

    except ValueError:
        print(f"{C_RED}Invalid input.{C_RESET}")
    except KeyboardInterrupt:
        sys.exit(0)


if __name__ == "__main__":
    main()