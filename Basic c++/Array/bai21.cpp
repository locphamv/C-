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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != a[j][i])
            {

                return false;
            }
        }
    }
    return true;
}

int main()
{
    int m, n;
    cin >> m >> n;
    float a[100][100];
    nhapMang(a, n);
    bool g = kiemTra(a, n);
    if (g)
    {
        cout << "Yes";
    }
    else
        cout << "No";
    return 0;
}