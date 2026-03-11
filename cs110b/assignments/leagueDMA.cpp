//assignment 5: Lotuseana Ng

#include <iostream>
using namespace std;

void initializeArrays(string *nameptr, int *winptr, int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << "enter team #" << i+1 << ": ";
        cin >> *(nameptr + i);

        cout << "enter the wins for team #" << i+1 << ": ";
        cin >> *(winptr + i);
    }

}

void sortData(string *nameptr, int *winptr, int size)
{
    bool swapped;
    do
    {
        swapped = false;
        for (int i = 0; i < size-1; i++)
        {
            if (*(winptr + i) < *(winptr + i +1))
            {
                int temp_w = *(winptr + i);
                *(winptr + i) = *(winptr + i +1);
                *(winptr + i +1) = temp_w;

                string temp_s = *(nameptr + i);
                *(nameptr + i) = *(nameptr + i + 1);
                *(nameptr + i + 1) = temp_s;

                swapped = true;
            }
        }
    }
    while (swapped);
}

void displayData(string *nameptr, int *winptr, int size)
{
    cout << "league standings: \n";
    for (int i = 0; i < size; i++)
    {
        cout << *(nameptr +i) << ": " << *(winptr + i) << "\n";
    }

}

int main()
{
    string *nameptr = NULL;
    int *winptr = NULL;
    int numTeams;
    cout << "how many teams are there?" << endl;
    cin >> numTeams;

    nameptr = new string[numTeams];
    winptr = new int[numTeams];

    initializeArrays(nameptr, winptr, numTeams);
    sortData(nameptr, winptr, numTeams);
    displayData(nameptr, winptr, numTeams);

    delete [] nameptr;
    delete [] winptr;

    nameptr = NULL;
    winptr = NULL;
}

/*
OUTPUT:

how many teams are there?
4
enter team #1: Padres
enter the wins for team #1: 75
enter team #2: Dodgers
enter the wins for team #2: 91
enter team #3: Giants
enter the wins for team #3: 92
enter team #4: Cubs
enter the wins for team #4: 65
league standings: 
Giants: 92
Dodgers: 91
Padres: 75
Cubs: 65

*/
