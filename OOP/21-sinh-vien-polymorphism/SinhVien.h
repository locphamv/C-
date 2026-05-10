#pragma once
#include <iostream>
#include <string>

class SinhVien
{
  private:
    std::string maSV, hoTen, diaChi;
    int tongTinChi;
    double dtb;

  public:
    SinhVien() = default;
    virtual void nhap();
    virtual void xuat() const;
    int getTinChi() const;
    double getDtb() const;
    virtual bool duDieuKien() const = 0;
    virtual ~SinhVien() = default;
};