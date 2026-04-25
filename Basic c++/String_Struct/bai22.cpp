#include <iostream>
#include <cmath>
using namespace std;

struct PhanSo
{
    long long tu;
    long long mau;
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

PhanSo Cong(PhanSo a, PhanSo b)
{
    PhanSo p;
    p.tu = a.tu * b.mau + b.tu * a.mau;
    p.mau = a.mau * b.mau;
    return p;
}

void Xuat(PhanSo p)
{
    if (p.tu == 0)
    {
        cout << 0;
        return;
    }
    int a = ucln(p.tu, p.mau);
    p.tu /= a;
    p.mau /= a;
    if (p.mau < 0)
    {
        p.mau = -p.mau;
        p.tu = -p.tu;
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
    Xuat(Cong(a, b));
    return 0;
}
