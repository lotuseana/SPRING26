//assignment 2: Lotuseana Ng

#include <iostream>
using namespace std;

char get_user_response_to_guess(int guess)
{
    cout << "Is it " << guess << "? (h/l/c) \n";
    char response;
    cin >> response;
    return response;
}

int get_midpoint(int low, int high)
{
    return (low + high) / 2;
    
}

void play_one_game()
{
    cout << "Think of a number between 1 and 100. \n";

    bool game_over = false;
    int cur_max = 100;
    int cur_min = 1;

    while (!game_over){
        int guess = get_midpoint(cur_min, cur_max);
        int response = get_user_response_to_guess(guess);

        if (response == 'h')
        {
            cur_min = guess + 1;
        }
        else if (response == 'l')
        {
            cur_max = guess - 1;
        }
        else if (response == 'c')
        {
            game_over = true;
        }
    }
    
}

bool should_play_again()
{
    cout << "Great! Do you want to play again? (y/n) \n";
    char response;
    cin >> response;
    if (response == 'y')
    {
        return true;
    }
    return false;
}

int main() 
{
  do 
  {
    play_one_game(); 
  } while (should_play_again());

  return 0;
}

/*
OUTPUT:
Think of a number between 1 and 100. 
Is it 50? (h/l/c) 
h
Is it 75? (h/l/c) 
l
Is it 62? (h/l/c) 
h
Is it 68? (h/l/c) 
l
Is it 65? (h/l/c) 
h
Is it 66? (h/l/c) 
h
Is it 67? (h/l/c) 
c
Great! Do you want to play again? (y/n) 
y
Think of a number between 1 and 100. 
Is it 50? (h/l/c)
h
Is it 75? (h/l/c) 
l
Is it 62? (h/l/c) 
l
Is it 56? (h/l/c) 
l
Is it 53? (h/l/c) 
c
Great! Do you want to play again? (y/n) 
n
*/