#include "SinhVien.h"
#include <cmath>
#include <iomanip>

SinhVien::SinhVien(string ten, string l, string ns, double gpa)
    : hoTen(ten), lop(l), ngaySinh(ns), GPA(gpa)
{
}

istream &operator>>(istream &is, SinhVien &a)
{
    a.ma = "B20DCCN001";
    getline(is, a.hoTen);
    is >> a.lop >> a.ngaySinh >> a.GPA;
    if (a.ngaySinh[2] != '/')
        a.ngaySinh = "0" + a.ngaySinh;
    if (a.ngaySinh[5] != '/')
        a.ngaySinh.insert(3, "0");
    return is;
}

ostream &operator<<(ostream &os, const SinhVien &a)
{
    os << a.ma << " " << a.hoTen << " " << a.lop << " " << a.ngaySinh << " " << setprecision(2)
       << fixed << a.GPA;
    return os;
}
