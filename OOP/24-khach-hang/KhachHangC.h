#pragma once
#include "KhachHang.h"

class KhachHangC : public KhachHang
{
public:
    void nhap(istream& in) override;
    double tinhTien() const override;
};