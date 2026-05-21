# checks password security and generates a salted SHA-512 hash.
import hashlib
import uuid

username = input("Enter username: ")
password = input("Enter password: ")

secure = True

if username in password or len(password) < 8 or password.isalpha():
    secure = False

salt = uuid.uuid4().hex

hashed_password = hashlib.sha512(password.encode()).hexdigest()

print("Salt:", salt)
print("Secure:", secure)
print("Hashed Password:", hashed_password)