#!/usr/bin/env python3

# runs three threads concurrently and waits for all to complete.
import threading
import time

class FetchDataThread(threading.Thread):
    def run(self):
        time.sleep(1)
        print("Fetching data complete.")

class ProcessDataThread(threading.Thread):
    def run(self):
        time.sleep(2)
        print("Processing data complete.")

class SaveDataThread(threading.Tread):
    def run(self):
        time.sleep(3)
        print("Saving data complete.")

def run_three_threads():
    t1 = FetchDataThread()
    t2 = ProcessDataThread()
    t3 = SaveDataThread()

    t1.start()
    t2.start()
    t3.start()

    t1.join()
    t2.join()
    t3.join()

run_three_threads()