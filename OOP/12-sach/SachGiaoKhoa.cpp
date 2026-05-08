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

void SachGiaoKhoa::xuat() const
{
    Sach::xuat();
    cout << "Tinh trang sach: " << tinhTrang << endl;
    cout << "Thanh tien: " << tinhTien() << endl;
}

double SachGiaoKhoa::tinhTien() const
{
    double tmp = getSoLuong() * getDonGia();
    if (tinhTrang == "moi")
    {
        return tmp;
    }
    else
    {
        return tmp / 2.0;
    }
}