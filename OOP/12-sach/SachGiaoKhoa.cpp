#include "SachGiaoKhoa.h"
using namespace std;

SachGiaoKhoa::SachGiaoKhoa() : Sach(), tinhTrang("")
{
}

void SachGiaoKhoa::nhap()
{
    Sach::nhap();
    cout << "Nhap tinh trang sach (moi hoac cu): ";
    cin >> tinhTrang;
}

void SachGiaoKhoa::xuat()
{
    Sach::xuat();
    cout << "Tinh trang sach: " << tinhTrang << endl;
}

void SachGiaoKhoa::tinhTien()
{
    double tmp = getSoLuong() * getDonGia();
    if (tinhTrang == "moi")
    {
        cout << tmp;
    }
    else
    {
        cout << tmp / 2.0;
    }
}