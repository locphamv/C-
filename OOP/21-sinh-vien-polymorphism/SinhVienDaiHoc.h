#pragma once
#include "SinhVien.h"

class SinhVienDaiHoc : public SinhVien
{
  private:
    std::string tenLuanVan;
    double diemLuanVan;

  public:
    SinhVienDaiHoc() = default;
    void nhap() override;
    void xuat() const override;
    bool duDieuKien() const override;
};
