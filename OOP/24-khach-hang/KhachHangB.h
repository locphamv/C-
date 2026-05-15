#pragma once
#include "KhachHang.h"

class KhachHangB : public KhachHang
{
private:
    int soNamThanThiet;

public:
    void nhap(istream& in) override;
    double tinhTien() const override;
};