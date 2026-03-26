#include "cSoPhuc.h"
#include <iostream>
using namespace std;

cSoPhuc::cSoPhuc()
{
    phanThuc = 0;
    phanAo = 0;
}

cSoPhuc::cSoPhuc(float Thuc, float Ao)
{
    phanThuc = Thuc;
    phanAo = Ao;
}

void cSoPhuc::ganGiaTri(float thuc, float ao)
{
    phanThuc = thuc;
    phanAo = ao;
}

cSoPhuc cSoPhuc::nhap()
{
    cout << "Nhap phan thuc: ";
    cin >> phanThuc;
    cout << "Nhap phan ao: ";
    cin >> phanAo;
}

void cSoPhuc::xuat()
{
    cout << "(" << phanThuc << ", " << phanAo << ")";
}
cSoPhuc cSoPhuc::operator+(cSoPhuc b)
{
    cSoPhuc kq;
    kq.phanThuc = phanThuc + b.phanThuc;
    kq.phanAo = phanAo + b.phanAo;
    return kq;
}

cSoPhuc cSoPhuc::operator-(cSoPhuc b)
{
    cSoPhuc kq;
    kq.phanThuc = phanThuc - b.phanThuc;
    kq.phanAo = phanAo - b.phanAo;
    return kq;
}

cSoPhuc cSoPhuc::operator*(cSoPhuc b)
{
    cSoPhuc kq;
    kq.phanThuc = phanThuc * b.phanThuc - phanAo * b.phanAo;
    kq.phanAo = phanThuc * b.phanAo + phanAo * b.phanThuc;
    return kq;
}

cSoPhuc cSoPhuc::operator/(cSoPhuc b)
{
    cSoPhuc kq;
    float mau = b.phanThuc * b.phanThuc + b.phanAo * b.phanAo;

    kq.phanThuc = (phanThuc * b.phanThuc + phanAo * b.phanAo) / mau;
    kq.phanAo = (phanAo * b.phanThuc - phanThuc * b.phanAo) / mau;

    return kq;
}

int cSoPhuc::laSo0()
{
    if (phanThuc == 0 && phanAo == 0)
        return 1;
    return 0;
}