#pragma once
#include <iostream>
#include <string>
using namespace std;

class KhachHang
{
protected:
    string tenKhachHang;
    long long soLuongHang;
    double donGiaHang;

    void nhapChung(istream& in);

public:
    virtual ~KhachHang() = default;

    virtual void nhap(istream& in) = 0;
    virtual double tinhTien() const = 0;
    virtual void xuat(ostream& out) const;
};