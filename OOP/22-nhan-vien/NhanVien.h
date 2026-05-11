#pragma once
#include <iostream>
#include <string>

class NhanVien
{
  protected:
    std::string ma, ten, sdt, email;
    int tuoi;
    double luongCB;

  public:
    virtual void nhap();
    virtual void xuat() const;
    virtual double tinhLuong() const = 0;
    virtual ~NhanVien() = default;
};