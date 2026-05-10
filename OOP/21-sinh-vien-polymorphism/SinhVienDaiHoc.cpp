#include "SinhVienDaiHoc.h"
using namespace std;

void SinhVienDaiHoc::nhap()
{
    SinhVien::nhap();
    cout << "Nhap ten luan van: ";
    getline(cin >> ws, tenLuanVan);
    cout << "Nhap diem luan van: ";
    cin >> diemLuanVan;
}

void SinhVienDaiHoc::xuat() const
{
    SinhVien::xuat();
    cout << "Ten luan van: " << tenLuanVan << endl;
    cout << "Diem luan van: " << diemLuanVan << endl;
}

bool SinhVienDaiHoc::duDieuKien() const
{
    return getTinChi() >= 145 && getDtb() >= 5 && diemLuanVan >= 5;
}