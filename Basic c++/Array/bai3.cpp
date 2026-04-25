#include <iostream>
using namespace std;

void nhapMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void xoaPhanTu(int a[], int &n, int p, int k)
{
    for (int i = p; i < n; i++)
    {
        a[i] = a[i + k];
    }
    n = n - k;
}
void xuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    int A[n];
    nhapMang(A, n);

    int p, k;
    cin >> p >> k;
    xoaPhanTu(A, n, p, k);

    xuatMang(A, n);
    return 0;
}