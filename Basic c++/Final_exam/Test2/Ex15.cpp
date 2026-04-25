#include <iostream>
#include <string>
using namespace std;

void input(string a[], int n, int i = 0)
{
    if (i == n)
        return;
    cin >> a[i];
    input(a, n, i + 1);
}

double calculateBeats(string &s, int i = 0, double pre = 0.0)
{
    if (i == 4)
        return 0.0;
    double val;
    switch (s[i])
    {
    case 'N':
        val = 1.0;
        break;
    case 'T':
        val = 1.0;
        break;
    case 'D':
        val = 0.5;
        break;
    case '_':
        val = pre;
    }
    return val + calculateBeats(s, i + 1, val);
}

bool checkBeats(string a[], int n, int i = 0)
{
    if (i == n)
        return true;
    if (calculateBeats(a[i]) != 4)
    {
        return false;
    }
    return checkBeats(a, n, i + 1);
}

int main()
{
    int n;
    cin >> n;
    string *beats = new string[n];
    input(beats, n);
    if (checkBeats(beats, n))
    {
        cout << "Harmony";
    }
    else
        cout << "Noise";
    return 0;
}