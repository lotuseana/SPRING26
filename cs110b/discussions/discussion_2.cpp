// discussion 2: Lotuseana Ng

#include <iostream>
using namespace std;

int main()
{
    char repeat;
        do
        {
            int home_score, away_score;
            cout << "What was the score for the home team? \n";
            cin >> home_score;
            cout << "What was the score for the away team? \n";
            cin >> away_score;

            if (home_score > away_score)
            {
                cout << "The home team won the game. \n";
            }
            else if (away_score > home_score)
            {
                cout << "The away team won the game. \n";
            }
            else
            {                    
                cout << "The teams tied. \n";
            }
            
            cout << "Go again? (y/n) \n";
            cin >> repeat;
        }
        while (repeat == 'y');
}

/*
OUTPUT:

[lng125@hills ~]$ ./a.out
What was the score for the home team?
10
What was the score for the away team?
20
The away team won the game.
Go again? (y/n)
y
What was the score for the home team?
5
What was the score for the away team?
5
The teams tied.
Go again? (y/n)
y
What was the score for the home team?
1
What was the score for the away team?
1
The teams tied.
Go again? (y/n)
y
What was the score for the home team?
5
What was the score for the away team?
2
The home team won the game.
Go again? (y/n)
n
[lng125@hills ~]$
*/