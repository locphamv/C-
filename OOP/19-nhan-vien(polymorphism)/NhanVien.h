#pragma once
#include <iostream>
#include <string>

class NhanVien
{
  private:
    std::string hoTen, ngaySinh; // ngay sinh: dd/mm/yyyy

  public:
    NhanVien();
    virtual void nhap();
    virtual void xuat() const;
    virtual double tinhLuong() const = 0;
    std::string getNgaySinh() const;
    void chuanHoaNgay(std::string& ngay);
    virtual ~NhanVien()
    {
    }
};
