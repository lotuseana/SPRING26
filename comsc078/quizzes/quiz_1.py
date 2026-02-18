#defining multiply function
def multiply(x, y):
    #recursion base case after done decrementing
    if (y == 0):
        #returning 0 for base case
        return 0
    #recursive step; adding current x value, then decrementing amount of times to add x value
    return x + multiply(x, y-1)


#defining main function
def main():
    #prompting user for wall space in square feet
    print("enter square feet of wall space to be painted: \n")
    wall_space = float(input())

    #prompting user for price per galloon of paint
    print("enter price of paint per gallon: \n")
    price_per_gallon = float(input())

    #paint needed = (wall space) * (1 gallon / 112 square feet)
    paint_needed = wall_space/112

    #hours needed is 8 times gallons of paint needed
    hours_needed = 8 * paint_needed

    #cost of paint is the price per gallon times gallons of paint 
    cost_of_paint = price_per_gallon * paint_needed

    #labor cost is hours of labor times charge per hour
    labor_charges = hours_needed * 35

    #total cost is cost of paint plus labor charges
    total_cost = cost_of_paint + labor_charges

    #printing out all the info for the user
    print("# of gallons of paint needed: " + str(paint_needed))
    print("hours of labor needed: " + str(hours_needed))
    print("cost of paint: " + str(cost_of_paint))
    print("labor charges: " + str(labor_charges))
    print("total cost of paint job: " + str(total_cost))

#calling main function
main()