#include "KiemChungVien.h"
using namespace std;

void KiemChungVien::nhap()
{
    NhanVien::nhap();
    cout << "Nhap so loi: ";
    cin >> soLoi;
}

void KiemChungVien::xuat() const
{
    NhanVien::xuat();
    cout << "So loi: " << soLoi << endl;
    cout << "Tong luong: " << tinhLuong() << endl;
}

double KiemChungVien::tinhLuong() const
{
    return luongCB + soLoi * 50000;
}