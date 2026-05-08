#pragma once
#include "Sach.h"

class SachGiaoKhoa: public Sach
{
    std:: string tinhTrang;

  public:
    SachGiaoKhoa();
    void nhap();
    void xuat() const;
    double tinhTien() const;
};