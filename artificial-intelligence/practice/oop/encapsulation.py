# Encapsulation

class BadBankAccount:
    def __init__(self, balance):
        self.balance = balance


account = BadBankAccount(0.0)
account.balance = -1
print(account.balance)


class BankAccount:
    def __init__(self):
        self._balance = 0.0

    @property
    def balance(self):
        return self._balance

    def deposit(self, amount):
        if self._is_valid_deposit(amount):
            raise ValueError("Deposit amount must be positive")
        self._balance += amount

    def _is_valid_deposit(self, amount):
        return 0 <= amount <= self._balance

    def withdraw(self, amount):
        if amount <= 0:
            raise ValueError("Withdraw amount must be positive")
        elif amount > self.balance:
            raise ValueError("Withdraw amount exceeds account balance")
        else:
            self._balance -= amount

    def _is_valid_withdraw(self, amount):
        return 0 <= amount <= self._balance

    @staticmethod
    def is_interest_rate_valid(interest_rate):
        return 0 <= interest_rate <= 5


account1 = BankAccount()
print(account1.balance)
account1.deposit(100)
print(account1.balance)
