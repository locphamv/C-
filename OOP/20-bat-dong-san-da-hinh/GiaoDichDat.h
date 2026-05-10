#pragma once
#include "GiaoDich.h"

class GiaoDichDat : public GiaoDich
{
  private:
    std::string loaiDat;

  public:
    GiaoDichDat(std::string loai = "");
    void nhap()   override;
    void xuat() const override;
    double thanhTien() const override;
};