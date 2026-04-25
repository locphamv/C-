#include <iostream>
#include <cmath>
using namespace std;
#define MAXN 105

struct PhanSo
{
    long long tu;
    long long mau;
};

void Nhap(PhanSo a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].tu >> a[i].mau;
    }
}
long long ucln(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while (b != 0)
    {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

void Xuat(PhanSo a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        if (a[i].mau == 0)
        {
            cout << "Khong thoa yeu cau bai toan" << endl;
            continue;
        }
        int k = ucln(a[i].tu, a[i].mau);
        a[i].tu /= k;
        a[i].mau /= k;
        if (a[i].mau < 0)
        {
            a[i].tu = -a[i].tu;
            a[i].mau = -a[i].mau;
        }
        if (a[i].mau == 1)
        {
            cout << a[i].tu << endl;
            continue;
        }
        cout << a[i].tu << "/" << a[i].mau << endl;
    }
}

int main()
{
    PhanSo a[MAXN];
    int n;
    Nhap(a, n);
    Xuat(a, n);
    return 0;
}
