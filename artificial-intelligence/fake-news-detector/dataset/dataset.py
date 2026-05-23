import kagglehub

# Download latest version
path = kagglehub.dataset_download("vcclab/welfake-dataset")

print("Path to dataset files:", path)