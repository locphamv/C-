#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char *a = new char[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int v = 0;
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 'U')
        {
            v++;
        }
        else
        {
            v--;
        }

        if (a[i] == 'U' && v == 0)
        {
            dem++;
        }
    }

    cout << dem;
    delete[] a;
    return 0;
}