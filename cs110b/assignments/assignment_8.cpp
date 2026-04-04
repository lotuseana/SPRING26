#include <iostream>
using namespace std;

const int MAX_CHARS = 128;

int lastIndexOf(char *s, char target)
{
    int i = 0;
    while (*(s+i) != '\0')
    {
        if (*(s+i)==target)
        {
            return i;
        }
        i++;
    }
    return -1;
}

void reverse(char *s)
{
    int len = 0;
    while (s[len] != '\0')
    {
        len++;
    }

    for (int i = 0; i < len / 2; i++)
    {
        char temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}

int replace(char *s, char target, char replacementChar)
{
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == target)
        {
            s[i] = replacementChar;
            count++;
        }
    }
    return count;
}

int findSubstring(char *s, char substring[])
{
    if (substring[0] == '\0')
        return 0;

    int sLen = 0;
    while (s[sLen] != '\0')
        sLen++;

    int subLen = 0;
    while (substring[subLen] != '\0')
        subLen++;

    if (subLen > sLen)
        return -1;

    for (int start = 0; start <= sLen - subLen; start++)
    {
        int k = 0;
        while (k < subLen && s[start + k] == substring[k])
            k++;

        if (k == subLen)
            return start;
    }

    return -1;
}

bool isWhitespaceChar(char c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f';
}

bool isPalindrome(char *s)
{
    int i = 0;
    int j = 0;
    while (s[j] != '\0')
        j++;
    j--;

    while (i < j)
    {
        while (i < j && isWhitespaceChar(s[i]))
            i++;
        while (i < j && isWhitespaceChar(s[j]))
            j--;

        if (i >= j)
            break;

        if (s[i] != s[j])
            return false;

        i++;
        j--;
    }

    return true;
}

int main()
{
    char s3[MAX_CHARS] = "Giants";
    cout << lastIndexOf(s3, 'a') << endl;

    char s4[MAX_CHARS] = "flower";
    reverse(s4);
    cout << s4 << endl;

    char s1[MAX_CHARS] = "go giants";
    int replacedCount = replace(s1, 'g', 'G');
    cout << s1 << endl;
    cout << replacedCount << endl;

    char s2[MAX_CHARS] = "Skyscraper";
    char substring1[] = "ysc";
    int idx = findSubstring(s2, substring1);
    cout << idx << endl;

    char p1[MAX_CHARS] = "abba";
    char p2[MAX_CHARS] = "hannah";
    char p3[MAX_CHARS] = "abc cba";
    char p4[MAX_CHARS] = "radar";

    cout << isPalindrome(p1) << endl;
    cout << isPalindrome(p2) << endl;
    cout << isPalindrome(p3) << endl;
    cout << isPalindrome(p4) << endl;

    return 0;
}

//OUTPUT:
//2
//rewolf
//Go Giants
//2
//2
//1
//1
//1
//1


