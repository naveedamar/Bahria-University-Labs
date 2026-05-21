# simulates a simple virus by selecting a target .txt file and appending malicious content.
import os

def SelectTarget():
    directory = "./"
    for item in os.listdir(directory):
        if os.path.isfile(os.path.join(directory, item)) and item.endswith(".txt"):
            return os.path.join(directory, item)

    default_target = "assignment_target.txt"
    with open(default_target, 'w') as f:
        f.write("Initial file content.\n")
    return default_target

def copy_code(file):
    with open(file, 'a') as f:
        f.write("hello from class 5a\n")

def infected(file):
    with open(file, 'a') as f:
        f.write("@.....infected.....@\n")

def payload(file):
    with open(file, 'a') as f:
        f.write("This is the first added line of the payload.\n")
        f.write("This is the second added line of the payload.\n")
        f.write("This is the third added line of the payload.\n")

def main():
    target = SelectTarget()

    if target:
        copy_code(target)
        infected(target)
        payload(target)
        print(f"Functions successfully executed on: {target}")

if __name__ == "__main__":
    main()