#include <iostream>
#include <string.h>
using namespace std;

int myStrlen(char s[], int k)
{
    int count = 0;
    while (s[count + k] != '\0')
    {
        count++;
    }
    return count;
}

int myStrcmp(char s1[], char s2[])
{
    int n = myStrlen(s1, 0);
    if (n > 0 && s1[n - 1] == '\n')
    {
        s1[n - 1] = '\0';
        n--;
    }
    int i = 0;
    while (s1[i] == s2[i])
    {

        if (s1[i] == '\0')
        {
            return 0;
        }
        i++;
    }
    if (s1[i] > s2[i])
    {
        return 1;
    }
    return -1;
}

void StringRev(char s[])
{
    int n = myStrlen(s, 0);
    if (n > 0 && s[n - 1] == '\n')
    {
        s[n - 1] = '\0';
        n--;
    }
    int start = 0;
    for (int i = 0; i <= n; i++)
    {
        if (s[i] == ' ' || s[i] == '\0')
        {
            int end = i - 1;
            int b = start;
            while (b < end)
            {
                char temp = s[b];
                s[b] = s[end];
                s[end] = temp;
                b++;
                end--;
            }
            start = i + 1;
        }
    }
}

int main()
{
    char s[300];
    fgets(s, 300, stdin);
    if (myStrcmp(s, "") == 0)
    {
        cout << "Chuoi rong.";
        return 0;
    }
    else
    {
        StringRev(s);
        cout << s;
    }
    return 0;
}