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
void xuatMang(float a[][100], int m, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    float a[100][100];
    cin >> m;
    cin >> n;
    nhapMang(a, m, n);

    xuatMang(a, m, n);
    return 0;
}