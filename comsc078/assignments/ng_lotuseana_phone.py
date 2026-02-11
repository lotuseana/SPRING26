def calculate_cost(units, base_cost, base_limit, cost_per_over):
    cost = base_cost
    if (units > base_limit):
        cost += (units-base_limit) * cost_per_over
    return cost

def get_units():
    print("enter number of units used:")
    return int(input())

def main():
    units = get_units()
    if (units<0):
        print("units cannot be negative.")
        return
    
    plan_1 = calculate_cost(units, 9.38, 65, 0.045)
    plan_2 = calculate_cost(units, 8.57, 50, 0.052)
    print("cost for plan 1: $" + f"{plan_1:.2f}")
    print("cost for plan 2: $" + f"{plan_2:.2f}")

    if (plan_1 < plan_2):
        print("plan 1 is cheaper.")
    else:
        print("plan 2 is cheaper.")

    return 0

main()