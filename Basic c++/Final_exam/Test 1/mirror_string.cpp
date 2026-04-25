#include <iostream>
#include <string.h>
using namespace std;

void run(char *s)
{
    int i = 0, l = 0;
    for (; s[l] != '\0'; l++)
        ;
    for (; s[i] != '\0'; i++)
        s[l - i - 1] = s[i];
}

int main()
{
    char s[100];
    cin.getline(s, 100);
    run(s);
    cout << s;
}