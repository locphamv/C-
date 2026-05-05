#pragma once
#include "GiaoDich.h"

class GiaoDichCanHo : public GiaoDich
{
  private:
    std::string maCan;
    int tang;
    public:
    GiaoDichCanHo(std::string maCan="",int tang=0);
    void nhap() override;
    void xuat()override;
    double thanhTien();
};