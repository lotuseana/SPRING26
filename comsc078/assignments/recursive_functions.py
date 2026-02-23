def display_em(lower, upper):
    if (lower > upper):
        return 0
    print(lower)
    return display_em(lower + 1, upper)

def add_em(lower, upper):
    if (lower > upper):
        return 0
    return lower + add_em(lower+1, upper)

def applyToEach(f, lower_bound, upper_bound):
    return f(lower_bound, upper_bound)

def main():
    lower = int(input("enter a lower bound: "))
    upper = int(input("enter an upper bound: "))

    print("the consecutive integers: ")
    applyToEach(display_em, lower, upper)
    print(f"add up to {applyToEach(add_em, lower, upper)}")

main()