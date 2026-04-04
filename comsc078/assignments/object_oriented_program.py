from datetime import datetime
import math

class GeometricObject:
    def __init__(self, color, filled):
        self.color = color
        self.filled = filled
        self.date_created = datetime.now()
        self.type = 'object'

    def __str__(self):
        to_string = f"""
        a {self.type} was created on {self.date_created}
        color of {self.type} is {self.color}
        filled: {self.filled}
        """

        if (self.type == 'circle'):
            to_string += f"""
            the radius is {self.radius}
            """
        elif (self.type == 'rectangle'):
            to_string += f"""
            the width is {self.width}
            the height is {self.height}
            """

        to_string += f"""
        the area is {self.area}
        the perimeter is {self.perimeter}
        """
        return to_string

    def get_color(self):
        return self.color
    
    def get_filled(self):
        return self.filled
    
    def get_date_created(self):
        return self.date_created
    
    def set_color(self, color):
        self.color = color

    def set_filled(self, filled):
        self.filled = filled

    def set_date_created(self, date_created):
        self.date_created = date_created

class Circle(GeometricObject):
    def __init__(self, color, filled, radius):
        super().__init__(color, filled)
        self.radius = radius
        self.type = 'circle'
        self.area = math.pi * (self.radius ** 2)
        self.perimeter = 2 * math.pi * self.radius

    def __str__(self):
        return super().__str__()

    def get_radius(self):
        return self.radius
    
    def set_radius(self, radius):
        self.radius = radius

    def get_area(self):
        return self.area
    
    def get_perimeter(self):
        return self.perimeter
    
class Rectangle(GeometricObject):
    def __init__(self, color, filled, width, height):
        super().__init__(color, filled)
        self.width = width
        self.height = height
        self.type = 'rectangle'
        self.area = self.height * self.width
        self.perimeter = (2 * self.height) + (2 * self.width)

    def __str__(self):
        return super().__str__()
    
    def get_width(self):
        return self.width
    
    def get_height(self):
        return self.height
    
    def set_width(self, width):
        self.width = width

    def set_height(self, height):
        self.height = height

    def get_area(self):
        return self.area
    
    def get_perimeter(self):
        return self.perimeter

def main():
    radius = float(input("enter the radius of your circle: "))

    circle = Circle('blue', True, radius)
    rectangle = Rectangle('red', False, 4.0, 2.0)

    print(circle)
    print()
    print(rectangle)

main()