// PhanSo.cpp
#include "PhanSo.h"
#include <cstdlib>
#include <numeric>

PhanSo::PhanSo(long long tu, long long mau) : Tu(tu), Mau(mau == 0 ? 1 : mau)
{
    chuanHoa();
}

long long gcd(const long long a, const long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void PhanSo::chuanHoa()
{
    if (Mau < 0)
    {
        Tu = -Tu;
        Mau = -Mau;
    }

    long long g = gcd(abs(Tu), abs(Mau));
    Tu /= g;
    Mau /= g;
}

PhanSo PhanSo::operator+(const PhanSo &other) const
{
    return PhanSo(Tu * other.Mau + other.Tu * Mau, Mau * other.Mau);
}

istream &operator>>(istream &is, PhanSo &ps)
{
    is >> ps.Tu >> ps.Mau;
    ps.chuanHoa();
    return is;
}

ostream &operator<<(ostream &os, const PhanSo &ps)
{
    os << ps.Tu << "/" << ps.Mau;
    return os;
}