#include "KhachHangA.h"

void KhachHangA::nhap(istream& in)
{
    nhapChung(in);
}

double KhachHangA::tinhTien() const
{
    double tamTinh = soLuongHang * donGiaHang;
    double vat = tamTinh * 0.10;
    return tamTinh + vat;
}