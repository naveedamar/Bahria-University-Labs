# implements a basic One-Time Pad (OTP) encryption and decryption algorithm using XOR.
import os

def generate_key(length):
    return os.urandom(length)

def encrypt(plaintext, key):
    plaintext_bytes = plaintext.encode('utf-8')
    ciphertext = bytearray()
    for i in range(len(plaintext_bytes)):
        ciphertext.append(plaintext_bytes[i] ^ key[i])
    return bytes(ciphertext)

def decrypt(ciphertext, key):
    decrypted_bytes = bytearray()
    for i in range(len(ciphertext)):
        decrypted_bytes.append(ciphertext[i] ^ key[i])
    return decrypted_bytes.decode('utf-8')

def main():
    message = "SECURE MESSAGE"
    key = generate_key(len(message))

    ciphertext = encrypt(message, key)
    decrypted_message = decrypt(ciphertext, key)
    print(f"Original Message: {message}")
    print(f"Key (Hex): {key.hex()}")
    print(f"Ciphertext (Hex): {ciphertext.hex()}")
    print(f"Decrypted Message: {decrypted_message}")

if __name__ == "__main__":
    main()