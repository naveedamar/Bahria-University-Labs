"""
key lessons:
1. what is self, how to use it
2. encapsulation, can be done by using _ prefix on attributes like: _password and _email ,this will not make it private,
    as _ prefixed attributes are by convention considered private by developers,
        2.1 if we want to really to make it private user __email ie: using double underscores,
            python will do name mangling ie: python will change name of the attribute to deny access outside of the class
"""

from datetime import datetime


class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def greet(self):
        print(f"Hello! my name is {self.name} and I am {self.age}.")


class User:
    def __init__(self, username, email, password):
        self.username = username
        self._email = email
        self.password = password

    # Even though we can access _email but as convention we don't access it directly
    def get_email(self):
        print(f"Email accessed at {datetime.now()}")
        return self._email

    # alternatively we can do the getter traditionally like in java
    @property
    def email(self):
        print("Email Accessed!")
        return self._email

    def set_email(self, new_email):
        if "@" in new_email:
            self._email = new_email

    # alternatively we can do the setter traditionally like in java
    @email.setter
    def email(self, new_email):
        if "@" in new_email:
            self._email = new_email

    def say_hi_to_user(self, user):
        print(
            f"Sending message to {user.username}: Hi {user.username}, it's {self.username}"
        )


person1 = Person("Naveed", 22)
person1.greet()

person2 = Person("Najm", 21)
person2.greet()

print("")
user1 = User("Naveed", "naveedamar@gmail.com", "1234")
user2 = User("Najm", "naju@gmail.com", "12345!")

user1.say_hi_to_user(user2)

print("")
# using property to access mail
print(f"Accing by using property {user1.email}")

print("")
print(f"Accing by using getter {user1.get_email()}")
user1.set_email("naveeddamar@gmail.com")
user2.set_email("naveeddamar@gmail.com")
print(f"Accing by using getter {user1.get_email()}")
