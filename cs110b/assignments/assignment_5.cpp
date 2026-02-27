//assignment 5: Lotuseana Ng

#include <iostream>
using namespace std;

void initializeArrays(string names[], int wins[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << "enter team #" << i+1 << ": ";
        cin >> names[i];

        cout << "enter the wins for team #" << i+1 << ": ";
        cin >> wins[i];
    }

}

void sortData(string names[], int wins[], int size)
{
    bool swapped;
    do
    {
        swapped = false;
        for (int i = 0; i < size-1; i++)
        {
            if (wins[i] < wins[i+1])
            {
                int temp_w = wins[i];
                wins[i] = wins[i+1];
                wins[i+1] = temp_w;

                string temp_s = names[i];
                names[i] = names[i+1];
                names[i+1] = temp_s;

                swapped = true;
            }
        }
    }
    while (swapped);
}

void displayData(string names[], int wins[], int size)
{
    cout << "league standings: \n";
    for (int i = 0; i < 5; i++)
    {
        cout << names[i] << ": " << wins[i] << "\n";
    }

}

int main()
{
    string names[5];
    int wins[5];

    initializeArrays(names, wins, 5);
    sortData(names, wins, 5);
    displayData(names, wins, 5);

}

/*
OUTPUT:

enter team #1: Padres
enter the wins for team #1: 75
enter team #2: Dodgers
enter the wins for team #2: 91
enter team #3: Giants
enter the wins for team #3: 92
enter team #4: Rockies
enter the wins for team #4: 65
enter team #5: Diamondbacks
enter the wins for team #5: 70
league standings: 
Giants: 92
Dodgers: 91
Padres: 75
Diamondbacks: 70
Rockies: 65
*/
