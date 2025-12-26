
#include <iostream>
#include <string.h>
using namespace std;
#define MAX 300

int myStrcmp(char s1[], char s2[]);
int myStrlen(char s[], int k);
void myStrcpy(char s[], int vt, char s1[], int k);
void mySubstr(char s[], int b, int count, char ss[]);
bool myStrcat(char s1[], char s2[]);
void StringReverse(char st[]);

int main()
{
    char s[MAX];
    fgets(s, MAX, stdin);
    if (myStrcmp(s, "") == 0)
        cout << "Chuoi rong." << endl;
    else
    {
        StringReverse(s);
        cout << s << endl;
    }
    return 0;
}

int myStrlen(char s[], int k)
{
    int i = k;
    int count = 0;
    while (s[i] != '\0')
    {
        count++;
        i++;
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
    return s1[i] - s2[i];
}

void reverse(char a[], int b, int e)
{
    while (b < e)
    {
        char tmp = a[b];
        a[b] = a[e];
        a[e] = tmp;
        b++;
        e--;
    }
}

void StringReverse(char st[])
{
    int n = myStrlen(st, 0);
    if (n > 0 && st[n - 1] == '\n')
    {
        st[n - 1] = '\0';
        n--;
    }

    reverse(st, 0, n - 1);

    int b = 0;
    for (int i = 0; i <= n; i++)
    {
        if (st[i] == ' ' || st[i] == '\0')
        {
            reverse(st, b, i - 1);
            b = i + 1;
        }
    }
}

void myStrcpy(char s[], int vt, char s1[], int k) {}
void mySubstr(char s[], int b, int count, char ss[]) {}
bool myStrcat(char s1[], char s2[]) { return true; }