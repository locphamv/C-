#pragma once
#include <iostream>
#include <string>

class Sach
{
    std::string ma, ngayNhap, nhaXuatBan;
    double donGia;
    int  soLuong;

  public:
    Sach();
    virtual void nhap();
    virtual void xuat() const;
    std::string getNxb() const;
    int getSoLuong() const;
    double getDonGia() const;
};

