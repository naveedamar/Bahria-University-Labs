shapes = ["circle", "square", "triangle"]

user_input = input("Enter a shape: ")

if user_input in shapes:
    print("Valid shape!")
else:
    print("Invalid shape!")