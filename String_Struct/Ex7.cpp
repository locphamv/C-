
#include <iostream>
#include <string.h>
using namespace std;
#define MAX 255

int myStrcmp(char s1[], char s2[]);

int main()
{
    char s1[MAX], s2[MAX];
    fgets(s1, MAX, stdin);
    fgets(s2, MAX, stdin);
    int kt = myStrcmp(s1, s2);
    cout << kt << endl;
    return 0;
}
int myStrcmp(char s1[], char s2[])
{
    int i = 0;

    while (s1[i] == s2[i])
    {
        if (s1[i] == '\0')
        {
            return 0;
        }
        i++;
    }

    if (s1[i] < s2[i])
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
