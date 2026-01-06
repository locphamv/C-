#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    int a[500][500];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            bool isMin = true;
            bool isMax = true;

            if (i - 1 >= 0)
            {
                if (a[i][j] >= a[i - 1][j])
                    isMin = false;
                if (a[i][j] <= a[i - 1][j])
                    isMax = false;
            }

            if (i + 1 < m)
            {
                if (a[i][j] >= a[i + 1][j])
                    isMin = false;
                if (a[i][j] <= a[i + 1][j])
                    isMax = false;
            }

            if (j - 1 >= 0)
            {
                if (a[i][j] >= a[i][j - 1])
                    isMin = false;
                if (a[i][j] <= a[i][j - 1])
                    isMax = false;
            }

            if (j + 1 < n)
            {
                if (a[i][j] >= a[i][j + 1])
                    isMin = false;
                if (a[i][j] <= a[i][j + 1])
                    isMax = false;
            }

            if (isMin)
                cout << "O";
            else if (isMax)
                cout << "X";
            else
                cout << a[i][j];

            if (j < n - 1)
                cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
