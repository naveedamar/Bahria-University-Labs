# static attributes and methods

class User:
    user_count = 0

    def __init__(self, username, email):
        self.username = username
        self.email = email
        User.user_count += 1

    def display_user(self):
        print(f"Username: {self.username}, Email: {self.email}")

class BankAccount:
    MIN_BALANCE = 100

    def __init__(self, owner, balance = 0):
        self.owner = owner
        self._balance = balance

    def deposit(self, amount):
        if self._is_valid_amount(amount):
            self._balance += amount
            self.__log_transaction("deposit", amount)
        else:
            print("Deposit amount cannot be negative")

    @staticmethod
    def is_valid_interest_rate(rate):
        return 0 <= rate <= 5

    def _is_valid_amount(self, amount):
        return amount > 0

    def __log_transaction(self, transaction_type, amount):
        print(f"Logging {transaction_type} of ${amount}. New balance: ${self._balance}")

#user class
user1 = User("user1", "user1@domain.com")
user2 = User("user2", "user2@domain.com")

print(User.user_count)
print(user1.user_count)
print(user2.user_count)

print("\n")
#bank class
account= BankAccount("Alice", 100)
account.deposit(200)

print(BankAccount.is_valid_interest_rate(3))
print(BankAccount.is_valid_interest_rate(10))


