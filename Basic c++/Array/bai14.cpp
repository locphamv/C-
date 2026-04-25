#include <iostream>
using namespace std;
#define MAX 100
int laysodau(int n)
{
    int a[100];

    while (n / 10 > 0)
    {
        n = n / 10;
    }
    return n;
}

bool isBenford(int a[], int n)
{
    int demso1 = 0;
    int demso4 = 0;
    for (int i = 0; i < n; i++)
    {
        if (laysodau(a[i]) == 1)
            demso1++;
        else if (laysodau(a[i]) == 4)
            demso4++;
    }
    if (demso1 == 3 && demso4 == 1)
        return true;
    else
        return false;
}
void Nhapmang(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

int main()
{
    int a[MAX], n = 10;
    Nhapmang(a, n);
    if (isBenford(a, n) == true)
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;
    return 0;
}