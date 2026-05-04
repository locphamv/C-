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
    virtual void xuat();
    std::string getNxb();
    int getSoLuong();
    double getDonGia();
};

