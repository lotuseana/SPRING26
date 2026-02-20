#assignment 3: higher-order functions. generalizes the summation function for square, fourth power, and square root
#Lotuseana Ng

from math import sqrt

def summation(f, lower, upper):
    total = 0
    for i in range (lower, upper+1):
        total += f(i)

    return total

def square(x):
    return x*x

def fourth_power(x):
    return square(square(x))

sqrt_sum = lambda lower, upper: summation(sqrt, lower, upper)

def main():
    lower_bound = int(input("enter a lower bound for the sum: "))
    upper_bound = int(input("enter an upper bound for the sum: "))

    print(f"the sum of squares of the numbers from {lower_bound} to {upper_bound} is {summation(square, lower_bound, upper_bound)}")
    print(f"the sum of the fourth powers of the numbers from {lower_bound} to {upper_bound} is {summation(fourth_power, lower_bound, upper_bound)}")
    print(f"the sum of square roots of the numbers from {lower_bound} to {upper_bound} is {sqrt_sum(lower_bound, upper_bound)}")


main()