#include "KhachHangB.h"
#include <algorithm>
using namespace std;

void KhachHangB::nhap(istream& in)
{
    nhapChung(in);
    in >> soNamThanThiet;
}

double KhachHangB::tinhTien() const
{
    double tamTinh = soLuongHang * donGiaHang;

    
    double tiLeKhuyenMai = max(soNamThanThiet * 0.05, 0.5);

    double sauKhuyenMai = tamTinh * (1.0 - tiLeKhuyenMai);
    double vat = sauKhuyenMai * 0.10;
    return sauKhuyenMai + vat;
}