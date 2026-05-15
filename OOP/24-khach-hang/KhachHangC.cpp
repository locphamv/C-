#include "KhachHangC.h"

void KhachHangC::nhap(istream& in)
{
    nhapChung(in);
}

double KhachHangC::tinhTien() const
{
    double tamTinh = soLuongHang * donGiaHang * 0.5;
    double vat = tamTinh * 0.10;
    return tamTinh + vat;
}