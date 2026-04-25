
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 300

void DemTieng(char s1[]);
int myStrcmp(char s1[], char s2[]);
int myStrlen(char s[], int k);
void myStrcpy(char s[], int vt, char s1[], int k);
void myMemmove(char s[], int vt, int k);
int myStrstr(char s[], char s1[]);
void mySubstr(char s[], int b, int count, char ss[]);
bool myStrcat(char s1[], char s2[]);

int main()
{
    char s[MAX];
    fgets(s, MAX, stdin);
    if (myStrcmp(s, "") == 0)
        cout << "Chuoi rong." << endl;
    else
        DemTieng(s);
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

int myStrcmp(char s1[], char s2[])
{
    int i = 0;
    while (s1[i] == s2[i])
    {
        if (s1[i] == '\0')
            return 0;
        i++;
    }

    return s1[i] - s2[i];
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

void DemTieng(char s1[])
{

    int len = myStrlen(s1, 0);
    if (len > 0 && s1[len - 1] == '\n')
    {
        s1[len - 1] = '\0';
        len--;
    }

    bool isEmpty = true;
    for (int i = 0; i < len; i++)
    {
        if (s1[i] != ' ')
        {
            isEmpty = false;
            break;
        }
    }
    if (len == 0 || isEmpty)
    {
        cout << "Chuoi rong." << endl;
        return;
    }

    char words[100][MAX];
    int counts[100] = {0};
    int n = 0;

    int i = 0;
    while (s1[i] != '\0')
    {

        while (s1[i] == ' ')
        {
            i++;
        }
        if (s1[i] == '\0')
            break;

        char temp[MAX];
        int j = 0;
        while (s1[i] != ' ' && s1[i] != '\0')
        {
            temp[j++] = s1[i++];
        }
        temp[j] = '\0';

        int found = -1;
        for (int k = 0; k < n; k++)
        {
            if (myStrcmp(words[k], temp) == 0)
            {
                found = k;
                break;
            }
        }

        if (found != -1)
        {
            counts[found]++;
        }
        else
        {
            myStrcpy(words[n], 0, temp, 0);
            counts[n] = 1;
            n++;
        }
    }

    for (int k = 0; k < n; k++)
    {
        cout << words[k] << ": " << counts[k] << endl;
    }
}
void myMemmove(char s[], int vt, int k)
{
    int n = myStrlen(s, 0);
    if (vt < 0 || vt >= n)
        return;

    for (int i = vt; i + k <= n; i++)
    {
        s[i] = s[i + k];
    }
}

bool myStrcat(char s1[], char s2[])
{
    int len1 = myStrlen(s1, 0);
    int len2 = myStrlen(s2, 0);

    if (len1 + len2 >= MAX)
        return false;

    int i = 0;
    while (s2[i] != '\0')
    {
        s1[len1 + i] = s2[i];
        i++;
    }
    s1[len1 + i] = '\0';
    return true;
}

int myStrstr(char s[], char s1[])
{
    int n = myStrlen(s, 0);
    int m = myStrlen(s1, 0);

    if (m == 0)
        return 0;

    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;

        while (j < m && s[i + j] == s1[j])
        {
            j++;
        }
        if (j == m)
            return i;
    }
    return -1;
}

void mySubstr(char s[], int b, int count, char ss[])
{
    int len = myStrlen(s, 0);
    int i = 0;

    while (i < count && (b + i) < len)
    {
        ss[i] = s[b + i];
        i++;
    }
    ss[i] = '\0';
}
