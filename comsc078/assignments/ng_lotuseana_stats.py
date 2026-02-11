# Lotuseana Ng
# CS 078
# Assignment 2: Math Functions


def reciprocal(num):
    return 1/num

def mean(num1, num2, num3):
    return (num1+num2+num3)/3

def geometric_mean(num1, num2, num3):
    return (num1*num2*num3)**(1/3)

def harmonic_mean(num1, num2, num3):
    return reciprocal(mean(reciprocal(num1), reciprocal(num2), reciprocal(num3)))

# this code goes AFTER your functions.

def main():
    print("Reciprocal of 8 is", reciprocal(8), "[should be 0.125]")
    print("Reciprocal of 4/3 is", reciprocal(4/3), "[should be 0.75]")
    print("Reciprocal of -3 is", reciprocal(-3), "[should be -0.3333...]")

    print("Mean of 1, 13, 4 is", mean(1, 13, 4), "[should be 6.0]")
    print("Mean of -5, -12, -9 is", mean(-5, -12, -9), "[should be -8.666...]")

    print("Geometric mean of 144, 2, 6 is", geometric_mean(144, 2, 6), \
        "[should be 11.9999..]")
    print("Geometric mean of 2.1, 16.8, 16.8 is", geometric_mean(2.1, 16.8, 16.8), \
        "[should be 8.3.999...]")
  
    print("Harmonic mean of 1, 2, 3 is", harmonic_mean(1, 2, 3), \
        "[should be 1.636363...]")
    print("Harmonic mean of -2, 1, 1 is", harmonic_mean(-2, 1, 1), \
        "[should be 2.0]")

main()

  
