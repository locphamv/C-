#include "LapTrinhVien.h"
using namespace std;

void LapTrinhVien::nhap()
{
    NhanVien::nhap();
    cout << "Nhap so gio lam: ";
    cin >> soGioLam;
}
void LapTrinhVien::xuat() const
{
    NhanVien::xuat();
    cout << "So gio lam: " << soGioLam << endl;
    cout << "Tong luong: " << tinhLuong() << endl;
}

double LapTrinhVien::tinhLuong() const
{
    return luongCB + 200000 * soGioLam;
}