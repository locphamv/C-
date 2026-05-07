#pragma once
#include "NhanVien.h"

class NhanVienSanXuat : public NhanVien
{
  private:
    double luongCoBan;
    int soSanPham;

  public:
    NhanVienSanXuat();
    void nhap() override;
    void xuat() const override;
    double tinhLuong() const;
};