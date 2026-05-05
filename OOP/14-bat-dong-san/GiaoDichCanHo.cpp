#include "GiaoDichCanHo.h"
using namespace std;

GiaoDichCanHo::GiaoDichCanHo(string maCan, int tang) : GiaoDich(), maCan(maCan), tang(tang)
{
}

void GiaoDichCanHo::nhap()
{
    GiaoDich::nhap();
    cout << "Nhap ma can ho: ";
    cin >> maCan;
    cout << "Nhap vi tri tang: ";
    cin >> tang;
}

void GiaoDichCanHo::xuat()
{
    GiaoDich::xuat();
    cout << "Ma can ho: " << maCan << endl;
    cout << "Vi tri tang: " << tang << endl;
    cout << "Thanh tien: " << thanhTien() << endl;
}

double GiaoDichCanHo::thanhTien()
{
    if (tang == 1)
    {
        return 2 * getDienTich() * getDonGia();
    }
    else if (tang >= 15)
        return 1.2 * getDienTich() * getDonGia();
    else
        return getDienTich() * getDonGia();
}