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
    bool ktra = true;
    if (m != n)
    {
        ktra = false;
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && a[i][j] != 0)
                {
                    ktra = false;
                    break;
                }
            }
            if (ktra == false)
            {
                break;
            }
        }
    }

    if (ktra == true)
    {
        cout << "Yes";
    }
    if (ktra == false)
    {
        cout << "No";
    }
    return 0;
}