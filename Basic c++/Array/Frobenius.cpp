#include <iostream>
using namespace std;

int main()
{
    int m, n;
    int a[500][500];
    cin >> m >> n;
    if (m != n)
    {
        cout << "No";
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int col = -1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j && a[i][j] != 1)
            {
                cout << "No";
                return 0;
            }
            if (i < j && a[i][j] != 0)
            {
                cout << "No";
                return 0;
            }
            if (i > j && a[i][j] != 0)
            {
                if (col == -1)
                {
                    col = j;
                }
                else
                {
                    if (col != j)
                    {
                        cout << "No";
                        return 0;
                    }
                }
            }
        }
    }

    cout << "Yes";
    return 0;
}