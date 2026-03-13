import subprocess

def display_user_activity():
    result = subprocess.run(['w'], capture_output=True, text=True)
    print(result.stdout)

display_user_activity()
