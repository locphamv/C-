#include <iostream>
using namespace std;

int main()
{
    int m, n;
    float a[100][100];
    cin >> m >> n;
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
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                tong += a[i][j];
            }
        }
    }
    cout << tong;
}