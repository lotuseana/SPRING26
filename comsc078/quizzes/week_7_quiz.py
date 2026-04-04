from random import randint

def generate_lottery_number():
    #define list for numbers
    nums = []
    #loop over amount of numbers
    for i in range(7):
        #generate a random integer digit
        num = randint(0,9)
        #add the generated integer into the list
        nums.append(num)

    #print each number with a loop
    for i in nums:  
        print(i)

def analyze_list():
    #define list for numbers
    nums = []
    #prompt number 20 times and add them to list
    for i in range(20):
        nums.append(int(input(f"enter number {i}: ")))

    #print the data
    print(f"lowest number: {min(nums)}")
    print(f"highest number: {max(nums)}")
    print(f"total: {sum(nums)}")
    print(f"average: {sum(nums)/len(nums)}")

def main():
    analyze_list()

main()

