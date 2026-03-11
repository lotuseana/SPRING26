

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

#function to find nearest prime given a number
def nearest_prime(num):

    #distance counter, which will increase every iteration. starts at 0 (checking if itself is prime)
    distance = 0

    #iterate until a prime is found
    while True:

        #first check the bigger number which is the number plus a positive distance that increases
        if prime_check(num+distance):
            return num+distance
        
        #then check the smaller number (plus a negative distance)
        if prime_check(num-distance):
            return num-distance
        
        #incrememnt distance
        distance += 1

def main():
    #user input for numbers
    num = int(input("enter a number: "))

    #print result of nearest_prime
    print(f"the nearest prime to {num} is {nearest_prime(num)}")


main()