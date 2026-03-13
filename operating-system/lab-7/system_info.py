import os
import platform
import datetime
from cryptography.fernet import Fernet

def display_system_info():
    print(f"OS: {platform.system()} {platform.release()}")
    print(f"Node Name: {platform.node()}")
    print(f"Architecture: {platform.machine()}")
    print(f"Current Time: {datetime.datetime.now()}")

def encrypt_file(filename):
    key = Fernet.generate_key()
    with open("secret.key", "wb") as key_file:
        key_file.write(key)
    
    cipher = Fernet(key)
    with open(filename, "rb") as f:
        file_data = f.read()
    
    encrypted_data = cipher.encrypt(file_data)
    with open(filename, "wb") as f:
        f.write(encrypted_data)
    print(f"File '{filename}' encrypted. Key saved to 'secret.key'.")

def get_file_stats(filename):
    lines = 0
    words = 0
    chars = 0
    with open(filename, 'r') as f:
        for line in f:
            lines += 1
            words += len(line.split())
            chars += len(line)
    print(f"Lines: {lines}, Words: {words}, Characters: {chars}")

def main():
    print("--- System Info ---")
    display_system_info()

    # Example filename - ensure this file exists in your directory
    test_file = "lab_report.txt"

    if os.path.exists(test_file):
        print(f"\n--- Stats for {test_file} ---")
        get_file_stats(test_file)

        print(f"\n--- Encrypting {test_file} ---")
        encrypt_file(test_file)
    else:
        print(f"\nFile '{test_file}' not found for stats/encryption.")

if __name__ == "__main__":
    main()
