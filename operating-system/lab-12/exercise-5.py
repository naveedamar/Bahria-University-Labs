# acts as an antivirus, scanning for and removing a specific viral signature from .txt files.
import os

VIRUS_SIGNATURE = "@.....You have been fooled@"
VIRUS_CODE = [
    "hello from class 5a\n",
    "@.....You have been fooled@\n",
    "This is the first added line of the payload.\n",
    "This is the second added line of the payload.\n",
    "This is the third added line of the payload.\n"
]

def scan():
    text_files = []
    directory = "./"
    for item in os.listdir(directory):
        if os.path.isfile(os.path.join(directory, item)) and item.endswith(".txt"):
            text_files.append(os.path.join(directory, item))
    return text_files

def find_target():
    infected_files = []
    files_to_check = scan()

    for file in files_to_check:
        try:
            with open(file, 'r') as f:
                content = f.read()
                if VIRUS_SIGNATURE in content:
                    infected_files.append(file)
        except Exception:
            pass

    return infected_files

def remove(file):
    try:
        with open(file, 'r') as f:
            lines = f.readlines()

        with open(file, 'w') as f:
            for line in lines:
                if line not in VIRUS_CODE:
                    f.write(line)
    except Exception:
        pass

def main():
    targets = find_target()
    
    if not targets:
        print("Scan complete. No infected files found.")
    else:
        for target in targets:
            remove(target)
            print(f"Viral code successfully removed from: {target}")

if __name__ == "__main__":
    main()