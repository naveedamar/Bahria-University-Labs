# Polymorphism

# Inheritance

class Vehicle:
    def __init__(self, brand, model, year):
        self.brand = brand
        self.model = model
        self.year = year

    def start(self):
        print("Vehicle is starting")

    def stop(self):
        print("Vehicle is stopping")


class Car(Vehicle):
    def __init__(self, brand, model, year, num_of_doors, num_of_wheels):
        super().__init__(brand, model, year)
        self.num_of_doors = num_of_doors
        self.num_of_wheels = num_of_wheels


class Bike(Vehicle):
    def __init__(self, brand, model, year, color):
        super().__init__(brand, model, year)
        self.color = color


vehicles: list[Vehicle] = [
    Car("Ford", "Focus", 2008, 5, 4),
    Bike("Honda", "Scoopy", 2015, "Red")
]

for vehicle in vehicles:
    print(f"Inspecting {vehicle.brand}, {vehicle.model}, {type(vehicle).__name__} ")
    vehicle.start()
    vehicle.stop()
    print("")
