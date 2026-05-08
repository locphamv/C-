#include "ChuyenXeNoiThanh.h"

ChuyenXeNoiThanh::ChuyenXeNoiThanh() : ChuyenXe(), soTuyen(0), soKm(0) {};

void ChuyenXeNoiThanh::nhap()
{
    ChuyenXe::nhap();
    cout << "Nhap so Tuyen: ";
    cin >> soTuyen;
    cout << "Nhap so km di duoc: ";
    cin >> soKm;
}

void ChuyenXeNoiThanh::xuat() const
{
    ChuyenXe::xuat();
    cout << "\nSo tuyen: " << soTuyen;
    cout << "\nSo km di duoc: " << soKm;
}