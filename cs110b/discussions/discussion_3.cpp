//q1

#include <iostream>
using namespace std;

float toCelsius(float f)
{
    return (f - 32) * 5 / 9;
}

int main()
{
    cout << "temperature table: \n";
    cout << "F      C\n";
    for (int i=60; i <=80; i++)
    {
        cout << i << "      " << toCelsius(i) << "\n";
    }
    return 0;
}