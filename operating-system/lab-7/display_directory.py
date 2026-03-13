import subprocess

def list_files_with_ls():
    result = subprocess.run(['ls'], capture_output=True, text=True)
    print(result.stdout)

list_files_with_ls()
