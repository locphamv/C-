#include "SinhVien.h"

istream &operator>>(istream &is, SinhVien &sv)
{
    is >> sv.ma;
    is.ignore();
    getline(is, sv.ten);
    is >> sv.lop >> sv.email;
    return is;
}

ostream &operator<<(ostream &os, const SinhVien &sv)
{
    os << sv.ma << " " << sv.ten << " " << sv.lop << " " << sv.email << endl;
    return os;
}

bool SinhVien::operator<(const SinhVien &other) const
{
    return this->ma<other.ma;
}

