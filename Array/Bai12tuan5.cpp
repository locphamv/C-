#include <iostream>
using namespace std;

void nhapMang(int a[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void xuatchisoleMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i % 2 != 0)
        {
            cout << a[i] << " ";
        }
    }
}

int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    int a[100];
    cout << "Nhap phan tu: ";
    nhapMang(a, n);
    cout << "Cac chi so le: ";
    xuatchisoleMang(a, n);
    return 0;
}