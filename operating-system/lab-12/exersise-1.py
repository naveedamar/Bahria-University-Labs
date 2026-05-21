import hashlib
import uuid

username = input("Enter username: ")
password = input("Enter password: ")

secure = False

if password != username and len(password) > 8 and password.isalpha():
    secure = True

salt = uuid.uuid4().hex
print("Salt:", salt)

hashed_password = hashlib.sha512(password.encode()).hexdigest()

print("Secure:", secure)
print("Hashed Password:", hashed_password)
