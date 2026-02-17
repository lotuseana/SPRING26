//assignment 4: Lotuseana Ng

#include <iostream>
using namespace std;

bool containsPair(int hand[])
{
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            if (i!=j && hand[i]==hand[j])
            {
                return true;
            }
        }
    }
    return false;
}

bool containsTwoPair(int hand[])
{
    int inds_pair[2];
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            if (i!=j && hand[i]==hand[j])
            {
                inds_pair[0]=i;
                inds_pair[1]=j;
            }
        }
    }
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            if (i!=inds_pair[0] && i!=inds_pair[1] && j!=inds_pair[0] && j!=inds_pair[1] && i!= j && hand[i]==hand[j])
            {
                return true;
            }
        }
        
    }
    return false;

}

bool containsThreeOfaKind(int hand[])
{
    int counters[3] = {0, 0, 0};
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (hand[i]==hand[j])
            {
                counters[j]++;
            }
        }
    }
    for (int i=0; i<3; i++)
    {
        if (counters[i]>=3)
        {
            return true;
        }
    }
    return false;
}

bool containsStraight(int hand[])
{
    int lowest = hand[0];
    for (int i=0; i<5; i++)
    {
        if (hand[i]<lowest)
        {
            lowest = hand[i];
        }
    }

    for (int i=lowest+1; i<lowest+5; i++)
    {
        bool present = false;
        for (int j=0; j<5; j++)
        {
            if (hand[j]==i)
            {
                present = true;
                break;
            }
        }
        if (!present)
        {
            return false;
        }
    }

    return true;
}

bool containsFullHouse(int hand[])
{
    int counters[3] = {0, 0, 0};
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (hand[i]==hand[j])
            {
                counters[j]++;
            }
        }
    }
    int val_triple=0;
    for (int i=0; i<3; i++)
    {
        if (counters[i]>=3)
        {
            val_triple = hand[i];
            break;
        }
    }
    if (val_triple==0)
    {
        return false;
    }
    int inds_triple[3];
    int cur_ind_triple = 0;
    for (int i=0; i<5; i++)
    {
        if (hand[i] == val_triple)
        {
            inds_triple[cur_ind_triple] = i;
            cur_ind_triple++;
        }
    }
    int ind_others[2];
    int cur_ind_other = 0;
    for (int i=0; i<5; i++)
    {
        if (i!=inds_triple[0] && i!=inds_triple[1] && i!=inds_triple[2])
        {
            ind_others[cur_ind_other] = i;
            cur_ind_other++;
        }
    }

    if (hand[ind_others[0]]==hand[ind_others[1]])
    {
        return true;
    }
    return false;
}

bool containsFourOfaKind(int hand[])
{
    int counter1 = 0;
    int counter2 = 0;
    for (int i=0; i<5; i++)
    {
        if (hand[i]==hand[0])
        {
            counter1++;
        }
        else if (hand[i]==hand[1])
        {
            counter2++;
        }
    }

    if (counter1>=4 || counter2>=4)
    {
        return true;
    }
    return false;
}
int main()
{
    int hand[5];

    cout << "Enter five numeric cards, no face cards. Use 2 - 9. \n";
    for (int i=0; i<5; i++)
    {
        cout << "Card " << i << ": ";
        cin >> hand[i];
    }

    if (containsFourOfaKind(hand)) 
    {
        cout << "Four of a kind!" << endl;
    }
    else if (containsFullHouse(hand))
    {
        cout << "Full house!" << endl;
    }
    else if (containsStraight(hand))
    {
        cout << "Straight!" << endl;
    }
    else if (containsThreeOfaKind(hand))
    {
        cout << "Three of a kind!" << endl;
    }
    else if (containsTwoPair(hand))
    {
        cout << "Two pair!" << endl;
    }
    else if (containsPair(hand))
    {
        cout << "Pair!" << endl;
    }
    else
    {
        cout << "High card!" << endl;
    }

    return 0;

}