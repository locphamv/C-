#include "GiaoDichVang.h"
using namespace std;

GiaoDichVang::GiaoDichVang(string loai) : GiaoDich(), loaiVang(loai)
{
}

void GiaoDichVang::nhap()
{
    GiaoDich::nhap();
    cout << "Nhap loai vang: ";
    cin >> loaiVang;
}

void GiaoDichVang::xuat()
{
    GiaoDich::xuat();
    cout << "Loai vang: " << loaiVang << endl;
    cout << "Thanh tien: " << tinhTien() << endl;
}

double GiaoDichVang::tinhTien()
{
    return getSoLuong() * getDonGia();
}