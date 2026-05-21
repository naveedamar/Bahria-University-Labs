#!/usr/bin/env python3

# demonstrates checking a thread's alive status at various stages.
import threading
import time

class EnhancedThread(threading.Thread):
    def __init__(self, name):
        super().__init__()
        self.thread_name = name
        self.task_completed = False

    def display_status(self):
        print(f"Thread {self.thread_name} completion status: {self.task_completed}")

    def run(self):
        time.sleep(3)
        self.task_completed = True
        self.display_status()

def check_alive_status():
    worker = EnhancedThread("Worker-1")
    
    print("Before start, is alive:", worker.is_alive())
    
    worker.start()
    print("Immediately after start, is alive:", worker.is_alive())
    
    time.sleep(1)
    print("During execution, is alive:", worker.is_alive())
    
    worker.join()
    print("After join, is alive:", worker.is_alive())

check_alive_status()