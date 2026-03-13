def multiply_addition(a, b):
    result = 0
    for _ in range(b):
        result = result + a
    return result

a = int(input("Enter first number: "))
b = int(input("Enter second no: "))

result = multiply_addition(a,b)
print(f"Result =  {result}")
