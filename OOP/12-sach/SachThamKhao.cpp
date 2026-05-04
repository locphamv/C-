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

void SachThamKhao::xuat()
{
    Sach::xuat();
    cout << "Thue: " << thue << endl;
}

void SachThamKhao::tinhTien()
{

    cout << getSoLuong() * getDonGia() + thue;
}
