// assignment 0: Lotuseana Ng

#include <iostream>
using namespace std;

int main()
{
        int count;
        char repeat = 'y';
        while (repeat != 'n')
        {
                cout << "how many asterisks?: ";
                cin >> count;
                for (int i=0; i<count; i++)
                {
                        cout << "*";
                }
                cout << endl;
                cout << "go again? (y/n): ";
                cin >> repeat;
        }
        return 0;
}


/*
sample output:

[lng125@hills ~]$ ./a.out
how many asterisks?: 1
*
go again? (y/n): y
how many asterisks?: 5
*****
go again? (y/n): y
how many asterisks?: 10
**********
go again? (y/n): y
how many asterisks?: 2
**
go again? (y/n): n
[lng125@hills ~]$
*/