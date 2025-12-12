#include <iostream>
using namespace std;

int main()
{
    int m;
    int n;
    cin >> m >> n;
    float a[100][100];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    float tong = 0;
    for (int i = 0; i < m; i++)
    {
        int j = m - 1 - i;
        if (j >= 0 && j < m)
        {
            tong += a[i][j];
        }
    }
    cout << tong;
    return 0;
}