#include "KhachHang.h"
#include <iomanip>
using namespace std;

void KhachHang::nhapChung(istream& in)
{
    getline(in >> ws, tenKhachHang);
    in >> soLuongHang;
    in >> donGiaHang;
}

void KhachHang::xuat(ostream& out) const
{
    out << tenKhachHang << '\n';
    out << fixed << setprecision(2) << tinhTien() << '\n';
}