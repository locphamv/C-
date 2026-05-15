#pragma once
#include "KhachHang.h"

class KhachHangA : public KhachHang
{
public:
    void nhap(istream& in) override;
    double tinhTien() const override;
};
