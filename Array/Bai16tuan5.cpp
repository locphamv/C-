#include <iostream>
using namespace std;

void nhapMang(int a[100][100], int &n)
{
    cin >> n;
}

int traVeFibo(int sofibothu)
{
    int a[50];
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i < sofibothu; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[sofibothu - 1];
}

void xuatMang(int a[100][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << traVeFibo(i + j + 1) << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    int a[100][100];

    traVeFibo(4);
    nhapMang(a, n);

    xuatMang(a, n);

    return 0;
}