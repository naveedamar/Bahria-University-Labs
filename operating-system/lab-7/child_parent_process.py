import multiprocessing
import os

def child_task():
    print(f"Child process ID: {os.getpid()}")

def main():
    print(f"Parent process ID: {os.getpid()}")
    p = multiprocessing.Process(target=child_task)
    p.start()
    p.join()

if __name__ == "__main__":
    main()
