#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    int *b = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int j = 0; j < n; j++)
    {
        cin >> b[j];
    }
    int amax = 0;
    int bmin = 1000000005;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > amax)
        {
            amax = a[i];
        }
        if (b[i] < bmin)
        {
            bmin = b[i];
        }
    }
    if (bmin < amax)
    {
        cout << 0;
    }

    else
    {
        cout << bmin - amax + 1;
    }
    delete[] a;
    delete[] b;
    return 0;
}