#pragma once
#include <iostream>
#include <string>

class NhanVien
{
  private:
    std::string hoTen, ngaySinh;
  

  public:
    NhanVien();
    virtual void nhap();
    virtual void xuat() const;
};