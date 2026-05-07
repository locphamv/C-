#pragma once
#include "NhanVien.h"

class NhanVienVanPhong : public NhanVien
{
  private:
    int soNgayLam;

  public:
    NhanVienVanPhong();
    void nhap() override;
    void xuat() const override;
    double tinhLuong() const;
};
