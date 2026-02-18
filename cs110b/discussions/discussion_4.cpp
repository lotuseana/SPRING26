//q1

#include <iostream>
using namespace std;

int main()
{
    const int NUM_TYPES = 4;
    string burritoType[NUM_TYPES] = {"carnitas", "beef", "shrimp", "veggie"};
    int numSold[NUM_TYPES];

    for(int i = 0; i<NUM_TYPES; i++)
    {
        cout << "How many " << burritoType[i] << " burritos were sold? \n";
        cin >> numSold[i];
    }

    int totalBurritos = 0;
    int indexOfTypeMostSold = 0;
    for (int i = 0; i<NUM_TYPES; i++)
    {
        totalBurritos += numSold[i];
        if (numSold[i] > numSold[indexOfTypeMostSold])
        {
            indexOfTypeMostSold = i;
        }
    }
    cout << "Total number of burritos sold: " << totalBurritos << "\n";
    cout << "The type of burrito that sold the most: " << burritoType[indexOfTypeMostSold];

    return 0;
}