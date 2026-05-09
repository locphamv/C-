#include "NhanVienSanXuat.h"
using namespace std;
NhanVienSanXuat::NhanVienSanXuat() : NhanVien(), luongCoBan(0), soSanPham(0)
{
}

void NhanVienSanXuat::nhap()
{
    NhanVien::nhap();
    cout << "Nhap luong co ban: ";
    cin >> luongCoBan;
    cout << "Nhap so san pham: ";
    cin >> soSanPham;
}

void NhanVienSanXuat::xuat() const
{
    NhanVien::xuat();
    cout << "Luong can ban: " << luongCoBan << endl;
    cout << "So san pham: " << soSanPham << endl;
}

double NhanVienSanXuat::tinhLuong() const
{
    return luongCoBan + soSanPham * 5000;
}