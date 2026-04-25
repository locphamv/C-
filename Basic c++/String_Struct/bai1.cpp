
#include <iostream>
#include <string.h>
using namespace std;
#define MAX 300

int main()
{

    char s[MAX];
    cin.getline(s, MAX);

    for (int i = 0; s[i] != '\0'; i++)
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            cout << "CHUOI KHONG HOP LE.";
            return 0;
        }
    }
    cout << s;

    return 0;
}