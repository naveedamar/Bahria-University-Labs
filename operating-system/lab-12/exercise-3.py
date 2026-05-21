# demonstrates RSA public-key encryption, including key generation and encryption/decryption of a string.
import random
import math

def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(math.isqrt(num)) + 1):
        if num % i == 0:
            return False
    return True

def generate_prime(min_val, max_val):
    prime = random.randint(min_val, max_val)
    while not is_prime(prime):
        prime = random.randint(min_val, max_val)
    return prime

def generate_keypair(p, q):
    n = p * q
    phi = (p - 1) * (q - 1)

    e = random.randrange(2, phi)
    while math.gcd(e, phi) != 1:
        e = random.randrange(2, phi)

    d = pow(e, -1, phi)
    return ((e, n), (d, n))

def encrypt(public_key, plaintext):
    e, n = public_key
    return [pow(ord(char), e, n) for char in plaintext]

def decrypt(private_key, ciphertext):
    d, n = private_key
    return "".join([chr(pow(char, d, n)) for char in ciphertext])

def main():
    p = generate_prime(10, 100)
    q = generate_prime(10, 100)

    public_key, private_key = generate_keypair(p, q)

    message = "RSA"
    encrypted_msg = encrypt(public_key, message)
    decrypted_msg = decrypt(private_key, encrypted_msg)

    print(f"Public Key: {public_key}")
    print(f"Private Key: {private_key}")
    print(f"Original: {message}")
    print(f"Encrypted: {encrypted_msg}")
    print(f"Decrypted: {decrypted_msg}")

if __name__ == "__main__":
    main()