def multiplication_table():
    num = int(input("Enter the number for the table: "))
    start = int(input("Enter the starting range: "))
    end = int(input("Enter the ending range: "))

    for i in range(start, end + 1):
        print(f"{num} x {i} = {num * i}")

multiplication_table()
