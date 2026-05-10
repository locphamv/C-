#pragma once
#include "GiaoDich.h"

class GiaoDichNha : public GiaoDich
{
  private:
    std::string loaiNha, diaChi;

  public:
    GiaoDichNha(std::string loaiNha = "", std::string diaChi = "");
    void nhap() override;
    void xuat() const override;
    double thanhTien() const override;
};
