#pragma once
#include <iostream>
#include <string>

class GiaoDich
{
  private:
    std::string ma, ngay;
    double donGia, dienTich;

  public:
    GiaoDich(std::string ma = "", std::string ngay = "", double donGia=0, double dienTich=0);
    virtual void nhap();
    virtual void xuat();
    double getDonGia();
    double getDienTich();
    std::string getThangNgay();
};
