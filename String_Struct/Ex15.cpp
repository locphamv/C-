#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
    char s1[300];
    char s2[300];

    fgets(s1, 300, stdin);
    fgets(s2, 300, stdin);

    int i = 0;
    while (s1[i] == s2[i])
    {
        if (s1[i] == '\0')
        {
            cout << 0;
            return 0;
        }
        i++;
    }
    if (s1[i] > s2[i])
    {
        cout << 1;
        return 0;
    }
    cout << -1;

    return 0;
}