def license():
    #list of answers
    answers = [
        'A', 'C', 'A', 'A', 'D',
        'B', 'C', 'A', 'C', 'B',
        'A', 'D', 'C', 'A', 'D',
        'C', 'B', 'B', 'D', 'A'
    ]
    
    #keeping track of which questions were answered incorrectly
    incorrectly_answered = []

    #for each of the questions
    for i in range(20):
        #prompt user for what they got
        answer = input(f"enter answer for question {i + 1}: ")
        #if wrong, add it to the wrong answers
        if answer != answers[i]:
            incorrectly_answered.append(i+1)

    #count how many incorrect answers
    num_incorrect = len(incorrectly_answered)
    #print info
    print(f"number of correct answers: {20-num_incorrect}")
    print(f"number of incorrect answers: {num_incorrect}")

    #if scored below threshold, print that they failed. otherwise, they passed.
    if (20-num_incorrect >= 15):
        print("you passed the test.")
    else:
        print("you did not pass the test.")

    #print incorrectly answered without the list brackets
    print("questions answered incorrectly: " + str(incorrectly_answered)[1:-1])

def pig_latin(sentence):
    #split sentence up inta a list of words
    words = sentence.lower().split()
    #define vowels
    vowels = ['a', 'e', 'i', 'o', 'u']
    #declare new sentence
    new_sentence = ''
    #for each word in the sentence,
    for word in words:
        #if the first letter is a vowel, add "way" to the end
        if word[0] in vowels:
            new_sentence+= word + 'way '
        else:
            #determine the amount of consonents in the front of the word
            stopping_ind = 0
            #loop through until a vowel is hit
            while True:
                stopping_ind+=1
                #if the letter is a vowel or if there are no vowels in the word, break
                if word[stopping_ind] in vowels or stopping_ind == len(word):
                    break
            #get substring of leading consonents
            move_to_end = word[0:stopping_ind]
            #add new word to sentence
            new_sentence += word[stopping_ind:len(word)] + move_to_end + 'ay '
    #return new sentence
    return str(new_sentence)


def main():
    # license()
    #loop program
    while True:
        #prompt user input
        sentence = input("enter your sentence: ")
        #if empty input, break loop
        if sentence == '':
            break
        #call function
        print(pig_latin(sentence))
main()