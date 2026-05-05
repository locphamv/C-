#include "GiaoDichDat.h"
using namespace std;

GiaoDichDat::GiaoDichDat(string loai) : loaiDat(loai)
{
}

void GiaoDichDat::nhap()
{
    GiaoDich::nhap();
    cout << "Nhap loai dat(A,B,C): ";
    cin >> loaiDat;
}

void GiaoDichDat::xuat()
{
    GiaoDich::xuat();
    cout << "Loai dat: " << loaiDat << endl;
    cout << "Thanh tien: " << thanhTien() << endl;
}

double GiaoDichDat::thanhTien()
{
    if (loaiDat == "A")
    {
        return 1.5 * getDienTich() * getDonGia();
    }
    else
        return getDienTich() * getDonGia();
}
