#pragma once
#include "NhanVien.h"

class LapTrinhVien : public NhanVien
{
  private:
    int soGioLam;

  public:
    void nhap() override;
    void xuat() const override;
    double tinhLuong() const override;
};