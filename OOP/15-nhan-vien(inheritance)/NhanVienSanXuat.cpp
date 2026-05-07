#include "NhanVienSanXuat.h"
using namespace std;

NhanVienSanXuat::NhanVienSanXuat() : NhanVien(), luongCoBan(0), soSanPham(0)
{
}

void NhanVienSanXuat::nhap()
{
    NhanVien::nhap();
    cout << "Nhap so san pham: ";
    cin >> soSanPham;
    cout << "Nhap luong co ban: ";
    cin >> luongCoBan;
}

void NhanVienSanXuat::xuat() const
{
    NhanVien::xuat();
    cout << "So san pham: " << soSanPham << endl;
    cout << "Luong co ban: " << luongCoBan << endl;
    cout << "Luong = " << tinhLuong() << endl;
}

double NhanVienSanXuat::tinhLuong() const
{
    return luongCoBan + 5000 * soSanPham;
}