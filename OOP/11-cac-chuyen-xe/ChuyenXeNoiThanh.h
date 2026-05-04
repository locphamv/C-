#pragma once
#include "ChuyenXe.h"

class ChuyenXeNoiThanh : public ChuyenXe
{
  private:
    int soTuyen, soKm;

  public:
    ChuyenXeNoiThanh();

    void nhapXeNoiThanh();
    void xuatXeNoiThanh();
};
