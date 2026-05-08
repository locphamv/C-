#pragma once
#include "ChuyenXe.h"

class ChuyenXeNgoaiThanh : public ChuyenXe
{
  private:
    string noiDen;
    int soNgayDi;

  public:
    ChuyenXeNgoaiThanh();
    void nhap();
    void xuat()const;
};

