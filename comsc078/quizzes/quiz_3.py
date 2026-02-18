import random

#defining function to play one game
def play_one_game():
    #computer defines number to guess
    number = random.randint(1,100)

    #keeping track of guessed status
    guessed = False

    #looping while number has not been guessed
    while (not guessed):
        #prompting user guess
        guess = int(input("guess a number from 1-100: "))
        #logic for determining if the guess was correct
        if (guess>number):
            print("too high, try again.")
        elif (guess<number):
            print("too low, try again.")
        else:
            guessed = True


#defining function to generate 100 numbers
def generate_100():

    #defining parity variables
    num_odd = 0
    num_even = 0

    #defining array to store numbers
    nums = []

    #looping until 100 numbers
    for i in range(100):
        #current number is a random number between 1 and 100 (inclusive)
        num = random.randint(1,100)
        #logic for parity
        if (num % 2 == 0):
            num_even+=1
        else:
            num_odd+=1
        #adding current number to the array
        nums.append(num)

    #print statements to display data to user
    print(f"generated numbers: \n {nums}")
    print(f"number of odd numbers: {num_odd}")
    print(f"number of even numbers: {num_even}")

def main():
    #callng function to generate numbers
    generate_100()


#calling main
main()


    # #looping while user decides to play again
    # while True:
    #     #playing one game
    #     play_one_game()

    #     #user has guessed number
    #     print("congrats, you guessed the number!\n")

    #     #asking if user wants to play again
    #     replay = input("play again (y/n)?: ")

    #     #if user does not want to play again, terminate program
    #     if (replay!='y'):
    #         break