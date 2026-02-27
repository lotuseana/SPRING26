//q1

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int credit_cards[20];
    ifstream inputFile;
    inputFile.open("disc_5_cards.txt");

    if (!inputFile)
    {
        cout << "ERROR: Invalid File Name \n";
        exit(1);
    }

    for (int i=0; i<20; i++)
    {
        inputFile >> credit_cards[i];
    }

    int card_number;
    cout << "input credit card number: ";
    cin >> card_number;

    bool found = false;
    int low_ind = 0;
    int high_ind = 19;
    int middle_ind;

    while (!found && high_ind >= low_ind)
    {
        middle_ind = (low_ind + high_ind) / 2;
        if (credit_cards[middle_ind] > card_number)
        {
            high_ind = middle_ind - 1;
        }
        else if (credit_cards[middle_ind] < card_number)
        {
            low_ind = middle_ind + 1;
        }
        else
        {
            found = true;
        }
    }

    if (found)
    {
        cout << "ERROR: stolen credit card!";
    }
    else
    {
        cout << "success!";
    }

    inputFile.close();
}