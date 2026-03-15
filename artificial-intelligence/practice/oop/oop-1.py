# revising some topics, learning from yt: https://www.youtube.com/watch?v=iLRZi0Gu8Go&list=PPSV


class Dog:
    def __init__(self, name, breed, owner):
        self.name = name
        self.breed = breed
        self.owner = owner

    def bark(self):
        print("Woof Woof")


class Owner:
    def __init__(self, name, address, contact):
        self.name = name
        self.address = address
        self.contact = contact


def main():
    owner1 = Owner("Danny", "547 john street", "+91-1444")
    dog1 = Dog("Buddy", "Golden Retriever", owner1)

    owner2 = Owner("Sally", "123 springfield", "+91-16477")
    dog2 = Dog("Rex", "Bulldog", owner2)

    print(f"{dog1.name} is a {dog1.breed} and it's owner is {dog1.owner.name}")
    dog1.bark()

    print(f"\n{dog2.name} is a {dog2.breed} and it's owner is {dog2.owner.name}")
    dog2.bark()


if __name__ == "__main__":
    main()
