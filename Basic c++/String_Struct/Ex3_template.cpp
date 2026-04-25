
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 300

void DemKyTu(char s[]);
int myStrcmp(char s1[MAX], char s2[MAX]);
int myStrlen(char s[], int k);

int main()
{
    char s[MAX];
    fgets(s, MAX, stdin); // Nhap chuoi s
    if (myStrcmp(s, "") == 0)
        cout << "Chuoi rong." << endl;
    else
        DemKyTu(s);

    return 0;
}

int myStrlen(char s[], int k)
{
    if (s[k] == '\0')
    {
        return 0;
    }
    return 1 + myStrlen(s, k + 1);
}

int myStrcmp(char s1[MAX], char s2[MAX])
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
        {
            return s1[i] - s2[i];
        }
        i++;
    }
    return s1[i] - s2[i];
}

void DemKyTu(char s[])
{
    int len = myStrlen(s, 0);
    if (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r'))
    {
        s[len - 1] = '\0';
        len--;
    }
    if (len == 0)
    {
        cout << "Chuoi rong." << endl;
        return;
    }
    int dem[256] = {0};
    for (int i = 0; i < len; i++)
    {
        dem[s[i]]++;
    }
    for (int i = 0; i < len; i++)
    {
        if (dem[s[i]] > 0)
        {
            cout << s[i] << ": " << dem[s[i]] << endl;

            dem[s[i]] = 0;
        }
    }
}