#pragma once
#include "Sach.h"

class SachThamKhao: public Sach
{
    int thue;

  public:
    SachThamKhao();
    void nhap();
    void xuat()const;
    double tinhTien() const;
};