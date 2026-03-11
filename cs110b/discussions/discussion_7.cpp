//q1

#include <iostream>
using namespace std;

int main()
{
    const int NUM_TYPES = 3;
    string names[] = {"Carnitas", "Pollo", "Veggies"};
    float prices[] = {6.95, 6.25, 5.95};
    
    string *name_ptr = names;
    float *price_ptr = prices;

    for (int i = 0; i < NUM_TYPES; i++)
    {
        *(name_ptr + i) += " Especial";
        *(price_ptr + i) += 10.00;

        cout << *(name_ptr + i) << " -- " << *(price_ptr + i) << "\n";
    }
}

/*
OUTPUT: 

Carnitas Especial -- 16.95
Pollo Especial -- 16.25
Veggies Especial -- 15.95
*/