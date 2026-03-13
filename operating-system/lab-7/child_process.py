import os
import time

def process_creation():
    pid = os.fork()

    if pid < 0:
        print("Fork failed!")

    elif pid == 0:
        print(f"Child Process: PID = {os.getpid()}, PPID = {os.getppid()}")
        time.sleep(2)
        print("Child process finishing...")

    else:
        print(f"Parent Process: PID = {os.getpid()}, Child PID = {pid}")
        os.wait()
        print("Parent process finished after child.")

if __name__ == "__main__":
    process_creation()
