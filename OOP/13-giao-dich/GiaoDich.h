#pragma once
#include <iostream>
#include <string>

class GiaoDich
{
    std::string maGiaoDich, ngayGiaoDich;
    double donGia;
    int soLuong;

  public:
    GiaoDich(std::string ma = "", std::string ngay = "", double gia = 0, int so = 0);
    int getSoLuong();
    double getDonGia();
    virtual void nhap();
    virtual void xuat();
};
