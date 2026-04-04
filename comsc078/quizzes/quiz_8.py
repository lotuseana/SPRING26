class Car:
    def __init__(self, yearModel, make):
        self.yearModel = yearModel
        self.make = make
        self.speed = 0

    def get_yearModel(self):
        return self.yearModel

    def get_make(self):
        return self.make

    def get_speed(self):
        return self.speed

    def set_yearModel(self, yearModel):
        self.yearModel = yearModel

    def set_make(self, make):
        self.make = make
    
    def set_speed(self, speed):
        self.speed = speed

    def accelerate(self):
        self.speed += 5

    def brake(self):
        self.speed -= 5

def main():
    my_car = Car(2020, "camry")

    for i in range(5):
        my_car.accelerate()
        print(my_car.get_speed())

    for i in range(5):
        my_car.brake()
        print(my_car.get_speed())

main()





