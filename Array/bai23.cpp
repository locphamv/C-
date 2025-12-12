#include <iostream>
using namespace std;

void nhapMang(float a[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
}

void xuatTongMang(float a[][100], int m, int n, float b[][100], int l, int k)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] + b[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int m, n, l, k;
    float a[100][100];
    float b[100][100];
    cin >> m >> n;
    nhapMang(a, m, n);
    cin >> l >> k;
    nhapMang(b, l, k);
    xuatTongMang(a, m, n, b, l, k);
    return 0;
}