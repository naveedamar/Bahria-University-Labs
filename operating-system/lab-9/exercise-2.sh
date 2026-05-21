#!/usr/bin/env python3

# implements a thread pool working on a shared queue using locks.
import threading
import time
import queue

task_queue = queue.Queue()
thread_lock = threading.Lock()

class WorkerThread(threading.Thread):
    def __init__(self, name, q):
        super().__init__()
        self.name = name
        self.q = q

    def run(self):
        while not self.q.empty():
            task = self.q.get()
            
            thread_lock.acquire()
            
            print(f"{self.name} started processing: {task}")
            time.sleep(2)
            print(f"{self.name} finished processing: {task}\n")
            
            thread_lock.release()
            
            self.q.task_done()

def main():
    for i in range(1, 6):
        task_queue.put(f"Task-{i}")

    t1 = WorkerThread("Thread-1", task_queue)
    t2 = WorkerThread("Thread-2", task_queue)
    t3 = WorkerThread("Thread-3", task_queue)

    t1.start()
    t2.start()
    t3.start()

    task_queue.join()
    print("All tasks are complete!")

main()