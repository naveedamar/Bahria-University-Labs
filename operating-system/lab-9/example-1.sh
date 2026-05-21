#!/usr/bin/env python3

# demonstrates basic Python threading.
import threading
import time

class t1(threading.Thread):
    count = 0
    
    def __init__(self, name):
        threading.Thread.__init__(self)
        self.name = name
        
    def run(self):
        time.sleep(5)
        t1.count = t1.count + 1
        print("count--", t1.count)

def main():
    t11 = t1("T1")
    t11.start()
    t12 = t1("T2")
    t12.start()
    t13 = t1("T3")
    t13.start()
    t14 = t1("T4")
    t14.start()

main()