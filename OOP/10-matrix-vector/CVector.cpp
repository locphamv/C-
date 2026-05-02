#include "CVector.h"

CVector::CVector(int n) : phanTu(n, 0)
{
}

int CVector::soChieu() const
{
    return phanTu.size();
}

double CVector::layPhanTu(int i) const
{
    if (i >= 0 && i < phanTu.size())
        return phanTu[i];
    return 0;
}

void CVector::ganPhanTu(int i, double value)
{
    if (i >= 0 && i < phanTu.size())
        phanTu[i] = value;
}

CVector CVector::operator+(const CVector& other) const
{
    if (soChieu() != other.soChieu())
    {
        cout << "Khong cong duoc hai vector khac so chieu!" << endl;
        return CVector();
    }

    CVector kq(soChieu());

    for (int i = 0; i < soChieu(); i++)
    {
        kq.phanTu[i] = phanTu[i] + other.phanTu[i];
    }

    return kq;
}

CVector CVector::operator-(const CVector& other) const
{
    if (soChieu() != other.soChieu())
    {
        cout << "Khong tru duoc hai vector khac so chieu!" << endl;
        return CVector();
    }

    CVector kq(soChieu());

    for (int i = 0; i < soChieu(); i++)
    {
        kq.phanTu[i] = phanTu[i] - other.phanTu[i];
    }

    return kq;
}

void CVector::nhap(istream& is)
{
    int n;
    cout << "Nhap so chieu cua vector: ";
    is >> n;

    if (n < 0)
        n = 0;

    phanTu.resize(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan tu thu " << i << ": ";
        is >> phanTu[i];
    }
}

void CVector::xuat(ostream& os) const
{
    os << "(";
    for (int i = 0; i < phanTu.size(); i++)
    {
        os << phanTu[i];
        if (i != phanTu.size() - 1)
            os << ", ";
    }
    os << ")";
}

istream& operator>>(istream& is, CVector& v)
{
    v.nhap(is);
    return is;
}

ostream& operator<<(ostream& os, const CVector& v)
{
    v.xuat(os);
    return os;
}