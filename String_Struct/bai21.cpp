#include <iostream>
#include <cmath>
using namespace std;

struct PhanSo
{
    int tu;
    int mau;
};

void Nhap(PhanSo &p)
{
    cin >> p.tu >> p.mau;
}

PhanSo Nhap()
{
    PhanSo p;
    cin >> p.tu >> p.mau;
    return p;
}

PhanSo Chia(PhanSo p1, PhanSo p2)
{
    PhanSo thuong;
    thuong.tu = p1.tu * p2.mau;
    thuong.mau = p1.mau * p2.tu;
    return thuong;
}

int ucln(int a, int b)
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

void Xuat(PhanSo p)
{
    if (p.mau == 0)
    {
        return;
    }
    if (p.tu == p.mau)
    {
        cout << 1;
        return;
    }
    int k = ucln(p.tu, p.mau);
    p.tu /= k;
    p.mau /= k;

    if (p.mau < 0)
    {
        p.tu = -p.tu;
        p.mau = -p.mau;
    }
    if (p.mau == 1)
    {
        cout << p.tu;
        return;
    }
    cout << p.tu << "/" << p.mau;
}

int main()
{
    PhanSo a, b;
    Nhap(a);
    b = Nhap();
    Xuat(Chia(a, b));
    return 0;
}
