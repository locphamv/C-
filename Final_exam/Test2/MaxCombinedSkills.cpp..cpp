
#include <iostream>
#include <cmath>
using namespace std;

// 4 5
// 1 0 1 0 1
// 0 0 0 0 0
// 0 1 0 1 0
// 1 1 1 1 1

int maxThongThao(int a[][100], int m, int n, int socot)
{
    int dem = 0;
    for (int i = 0; i < socot; i++)
    {
        if (a[m][i] + a[n][i] != 0)
        {
            dem++;
        }
    }

    return dem;
}

// 4 5
// 1 0 1 0 1
// 0 0 0 0 0
// 0 1 0 1 0
// 1 1 1 1 1

int main()
{
    int n, m;
    cin >> n >> m;
    int a[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int k1[100];

    // 4 5
    // 1 0 1 0 1
    // 0 0 0 0 0
    // 0 1 0 1 0
    // 1 1 1 1 1
    int s = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            k1[s] = maxThongThao(a, i, j, m);
            s++;
        }
    }
    int max = k1[0];
    int dem = 1;
    for (int i = 1; i < s; i++)
    {
        if (k1[i] > max)
        {
            max = k1[i];
            dem = 1;
        }
        else if (k1[i] == max)
        {
            dem++;
        }
    }
    cout << max << endl
         << dem;
}
