#pragma once
#include "NhanVien.h"

class KiemChungVien : public NhanVien
{
  private:
    int soLoi;

  public:
    void nhap() override;
    void xuat() const override;
    double tinhLuong() const override;
};