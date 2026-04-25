#include <iostream>
using namespace std;

void nhapMang(float a[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
}

bool kiemTra(float a[][100], int n)
{
    int demchisocot = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j && a[i][j] != 1)
            {
                return false;
            }
            if (i != j)
            {
                if (i < j && a[i][j] != 0)
                {
                    return false;
                }
                if (i > j && a[i][j] != 0)
                {
                    if (demchisocot == -1)
                    {
                        demchisocot = j;
                    }
                    if (demchisocot != j)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    int m, n;
    float a[100][100];
    cin >> m >> n;
    nhapMang(a, n);
    if (kiemTra(a, n))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}
