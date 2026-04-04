// assignment 9: Lotuseana Ng

#include <iostream>
#include <cstring>
using namespace std;

struct WinRecord
{
    char *name;
    int wins;
};

char *getLine()
{
    const int BUFFER_SIZE = 1000;

    // Allocate a buffer local to this function
    char buffer[BUFFER_SIZE];

    // Use cin.getline() to input the buffer from the user
    cin.getline(buffer, BUFFER_SIZE);

    // Find the length of the string in buffer
    int length = strlen(buffer);

    // Dynamically allocate an array, to be returned
    char *rValue = new char[length + 1];

    // Copy the string into the dynamically allocated array
    strncpy(rValue, buffer, length);
    *(rValue + length) = '\0';


    // Return the address of the dynamically allocated array
    return rValue;
}

void initializeArrays(WinRecord *standings, int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << "enter team #" << i + 1 << ": ";
        (*(standings + i)).name = getLine();

        cout << "enter the wins for team #" << i + 1 << ": ";
        cin >> (*(standings + i)).wins;
        cin.ignore();
    }
}

void sortData(WinRecord *standings, int size)
{
    bool swapped;
    do
    {
        swapped = false;
        for (int i = 0; i < size - 1; i++)
        {
            if ((*(standings + i)).wins < (*(standings + i + 1)).wins)
            {
                WinRecord temp = *(standings + i);
                *(standings + i) = *(standings + i + 1);
                *(standings + i + 1) = temp;

                swapped = true;
            }
        }
    } while (swapped);
}

void displayData(WinRecord *standings, int size)
{
    cout << "league standings: \n";
    for (int i = 0; i < size; i++)
    {
        cout << (*(standings + i)).name << ": " << (*(standings + i)).wins << "\n";
    }
}

int main()
{

    WinRecord *standings = NULL;
    int size;
    cout << "how many teams are there?" << endl;
    cin >> size;
    cin.ignore();

    standings = new WinRecord[size];

    initializeArrays(standings, size);
    sortData(standings, size);
    displayData(standings, size);

    for (int i = 0; i < size; i++)
    {
        delete[] (*(standings + i)).name;
    }
    delete[] standings;
}

/*
OUTPUT:

how many teams are there?
3
enter team #1: warriors
enter the wins for team #1: 5
enter team #2: lakers
enter the wins for team #2: 11
enter team #3: wizards
enter the wins for team #3: 2
league standings: 
lakers: 11
warriors: 5
wizards: 2

*/
