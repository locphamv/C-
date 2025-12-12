#include <iostream>
using namespace std;

void nhapMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int secondVal(int a[], int n)
{
    int maxVal = 0;
    int secondmax = 0;
    for (int i = 0; i < n; i++)
    {
        if (maxVal < a[i])
        {
            maxVal = a[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (secondmax < a[i] && a[i] < maxVal)
        {
            secondmax = a[i];
        }
    }

    return secondmax;
}

int main()
{
    int n;
    int a[10005];
    cin >> n;
    nhapMang(a, n);
    cout << secondVal(a, n);
    return 0;
}