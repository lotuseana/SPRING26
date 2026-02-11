def to_decimal(degrees, minutes, seconds):
    return (abs(degrees) + (abs(minutes) / 60) + (abs(seconds) / 3600)) * degrees / abs(degrees)

def main():
    print("enter degrees:")
    degrees = int(input())
    print("enter minutes:")
    minutes = int(input())
    print("enter seconds:")
    seconds = float(input())
    print("that is", to_decimal(degrees, minutes, seconds), "decimal degrees.")
   
main()