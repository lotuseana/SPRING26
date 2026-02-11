//assignment 1: Lotuseana Ng

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int rand_card()
{
    return (rand() % (10)) + 1;
}

int main()
{
    srand(time(0));
    char play_again = 'n';
    
    do
    {
        int p_total, d_total;
        bool p_bust = false;
        bool d_bust = false;

        int d_cur_card = rand_card();
        cout << "dealer's first card: " << d_cur_card << "\n";
        d_total = d_cur_card;

        bool repeated = false;
        char hit = 'n';
        do {
            if (!repeated)
            {
                int p_card_1 = rand_card();
                int p_card_2 = rand_card();
                cout << "your starting hand: " << p_card_1 << ", " << p_card_2 << "\n";
                p_total = p_card_1 + p_card_2;
                repeated = true;
            }
            else
            {
                int p_cur_card = rand_card();
                cout << "your card: " << p_cur_card << "\n";
                p_total += p_cur_card;
            }
            cout << "your total: " << p_total << "\n";
            if (p_total > 21)
            {
                cout << "bust. \n";
                p_bust = true;
                break;
            }
            cout << "hit? (y/n) \n";
            cin >> hit;
        } while(hit == 'y');

        if (!p_bust){
            cout << "dealer has a " << d_cur_card << "\n";
            do
            {
                char cont;
                do 
                {
                    cout << "(c to continue) \n";
                    cin >> cont;
                } while(cont != 'c');

                d_cur_card = rand_card();
                cout << "dealer draws a " << d_cur_card << "\n";
                d_total += d_cur_card;
                cout << "dealer total: " << d_total << "\n";
                if (d_total > 21)
                {
                    cout << "bust. \n";
                    d_bust = true;
                    break;
                }
            } while(d_total < 17);
        }

        if ((p_total > d_total && !p_bust) || d_bust)
        {
            cout << "you win! \n";
        }
        else if ((d_total > p_total && !d_bust) || p_bust)
        {
            cout << "dealer wins! \n";
        }
        else
        {
            cout << "push! \n";
        }

        cout << "play again? (y/n) \n";
        cin >> play_again;


    } while(play_again == 'y');
    return 0;
}
/*
OUTPUT:
dealer's first card: 3
your starting hand: 9, 8
your total: 17
hit? (y/n) 
n
dealer has a 3
(c to continue) 
c
dealer draws a 4
dealer total: 7
(c to continue)
c
dealer draws a 10
dealer total: 17
push!
play again? (y/n)
y
dealer's first card: 9
your starting hand: 8, 2
your total: 10
hit? (y/n)
y
your card: 8
your total: 18
hit? (y/n)
n
dealer has a 9
(c to continue)
c
dealer draws a 7
dealer total: 16
dealer's first card: 9
your starting hand: 8, 2
your total: 10
hit? (y/n)
y
your card: 8
your total: 18
hit? (y/n)
n
dealer has a 9
(c to continue)
c
dealer draws a 7
dealer total: 16
your starting hand: 8, 2
your total: 10
hit? (y/n)
y
your card: 8
your total: 18
hit? (y/n)
n
dealer has a 9
(c to continue)
c
dealer draws a 7
dealer total: 16
your total: 18
hit? (y/n)
n
dealer has a 9
(c to continue)
c
dealer draws a 7
dealer total: 16
(c to continue)
c
dealer draws a 7
dealer total: 16
dealer total: 16
(c to continue)
c
dealer draws a 10
dealer total: 26
bust.
you win!
(c to continue)
c
dealer draws a 10
dealer total: 26
(c to continue)
(c to continue)
c
dealer draws a 10
dealer total: 26
bust.
you win!
play again? (y/n)
*/