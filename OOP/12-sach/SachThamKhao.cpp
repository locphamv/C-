#include "SachThamKhao.h"
using namespace std;

SachThamKhao::SachThamKhao() : Sach(), thue(0)
{
}

void SachThamKhao::nhap()
{
    Sach::nhap();
    cout << "Nhap thue: ";
    cin >> thue;
}

void SachThamKhao::xuat() const
{
    Sach::xuat();
    cout << "Thue: " << thue << endl;
    cout << "Thanh tien: " << tinhTien() << endl;
}

double SachThamKhao::tinhTien() const
{

    return getSoLuong() * getDonGia() + thue;
}
