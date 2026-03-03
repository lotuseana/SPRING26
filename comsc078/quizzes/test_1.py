
#function to calculate salaries
def calculate_salaries(days):
    #running sum of salaries
    sum = 0
    for i in range(days):
        #current salary given by 2^(i-1), then converted to dollars, for the ith day
        cur_salary = (2**(i) / 100)
        #printing current salary
        print(f"day {i+1}: ${cur_salary}")
        #adding current salary to the sum
        sum += cur_salary
    #returning the sum rounded to 2 decimal placess
    return round(sum, 2)

import math

def prime_check(num):
    #sieve of eratosthenes !!
    #array that will store all the primes up to sqrt(num) for efficient checking later
    prime = []
    #setting all to true at first; will tick them off to false as algorithm runs
    for i in range(int(math.sqrt(num) + 1)):
        prime.append(True)

    #starting from 2 (the first prime with nontrivial multiples), mark off multiples in the list as not prime
    for i in range(2, len(prime)):
        #only need to mark multiples of prime numbers. otherwise, the multiples will already be marked by its factors.
        if (prime[i]):
            #mark off all multiples of the number starting from i^2. for numbers less than i^2, they will already be marked off by other factors. 
            for j in range(i*i, len(prime), i):
                #set multiples to false (not prime)
                prime[j]=False

    #compile array of primes
    nums_to_check = []
    #if the ith index of the prime array is prime, add it to nums_to_check
    for i in range(2, len(prime)):
        if (prime[i]):
            nums_to_check.append(i)
    
    #print(nums_to_check) (check to make sure algorithm is working correctly)

    #if num is divisible by any of the primes in the array, it is not prime
    for i in nums_to_check:
        if (num % i == 0):
            return False

    return True

#recursive multiplication function
def multiply(x, y):
    #base case when x = 0
    if (x==0):
        return 0
    #recursive case: add y, then decrement the times y is added 
    return y + multiply(x-1, y)

def main():
    #user input for numbers
    num1 = int(input("enter a number: "))
    num2 = int(input("enter another number: "))

    #print the product
    print(f"{num1} times {num2} is {multiply(num1, num2)}")

main()