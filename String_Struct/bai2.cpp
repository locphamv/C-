#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 300

int myStrlen(char s[], int k);
void myStrcpy(char s[], int vt, char s1[], int k);
void mySubstr(char s[], int b, int count, char ss[]);
bool myStrcat(char s1[], char s2[]);
void ChenChuoiTaiVitriK(char s[], char s1[], int k);

int main()
{
    char s[MAX], s1[MAX];

    fgets(s, MAX, stdin);
    fgets(s1, MAX, stdin);
    int k;
    cin >> k;

    if (k < 0 || k > myStrlen(s, 0))
        cout << "Vi tri " << k << " khong thoa dieu kien." << endl;
    else
    {

        int len = myStrlen(s, 0);
        if (len > 0 && s[len - 1] == '\n')
        {
            s[len - 1] = '\0';
        }

        int newLen = myStrlen(s, 0);
        if (k > newLen)
            k = newLen;

        int len1 = myStrlen(s1, 0);
        if (len1 > 0 && s1[len1 - 1] == '\n')
        {
            s1[len1 - 1] = '\0';
        }

        ChenChuoiTaiVitriK(s, s1, k);
        cout << s;
    }
    return 0;
}

int myStrlen(char s[], int k)
{
    int count = 0;
    while (s[k + count] != '\0')
    {
        count++;
    }
    return count;
}

void myStrcpy(char s[], int vt, char s1[], int k)
{
    int i = 0;
    while (s1[k + i] != '\0')
    {
        s[vt + i] = s1[k + i];
        i++;
    }
    s[vt + i] = '\0';
}

void mySubstr(char s[], int b, int count, char ss[])
{
    int i;
    for (i = 0; i < count && s[b + i] != '\0'; i++)
    {
        ss[i] = s[b + i];
    }
    ss[i] = '\0';
}

bool myStrcat(char s1[], char s2[])
{
    int len1 = myStrlen(s1, 0);
    myStrcpy(s1, len1, s2, 0);
    return true;
}

void ChenChuoiTaiVitriK(char s[], char s1[], int k)
{

    char sub[MAX];

    int lenS = myStrlen(s, 0);
    mySubstr(s, k, lenS - k, sub);

    s[k] = '\0';

    myStrcat(s, s1);

    myStrcat(s, sub);
}