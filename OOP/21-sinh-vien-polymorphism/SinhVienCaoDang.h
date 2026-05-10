#pragma once
#include "SinhVien.h"

class SinhVienCaoDang : public SinhVien
{
  private:
    double dtn;

  public:
    SinhVienCaoDang() = default;
    void nhap()override;
    void xuat() const override;
    bool duDieuKien() const override;
};