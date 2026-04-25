#include <iostream>
using namespace std;

int countChar(int n)
{
    int dem = 0;
    if (n < 0)
    {
        n = -n;
        dem++;
    }
    if (n == 0)
        dem++;
    while (n > 0)
    {
        n /= 10;
        dem++;
    }
    return dem;
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        dem += countChar(a[i]);
    }

    cout << dem;

    delete[] a;
}