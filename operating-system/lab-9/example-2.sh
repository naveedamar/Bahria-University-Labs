#!/usr/bin/env python3

# demonstrates thread lifecycle checking and joining in Python.
import threading
import time

class MyThread(threading.Thread):
    def run(self):
        time.sleep(3)
        return

for i in range(3):
    thread = MyThread()
    thread.start()
    print("thread is alive =", thread.is_alive())
    thread.join()
    print("thread is alive=", thread.is_alive())