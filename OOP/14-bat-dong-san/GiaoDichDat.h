#pragma once
#include "GiaoDich.h"

class GiaoDichDat : public GiaoDich
{
  private:
    std::string loaiDat;

  public:
    GiaoDichDat(std::string loai = "");
    void nhap() override;
    void xuat() override;
    double thanhTien();
};