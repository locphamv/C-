#include "ChuyenXeNoiThanh.h"

ChuyenXeNoiThanh::ChuyenXeNoiThanh() : ChuyenXe(), soTuyen(0), soKm(0) {};

void ChuyenXeNoiThanh::nhapXeNoiThanh()
{
    ChuyenXe::nhap();
    cout << "Nhap so Tuyen: ";
    cin >> soTuyen;
    cout << "Nhap so km di duoc: ";
    cin >> soKm;
}

void ChuyenXeNoiThanh::xuatXeNoiThanh()
{
    ChuyenXe::xuat();
    cout << "\nSo tuyen: " << soTuyen;
    cout << "\nSo km di duoc: " << soKm;
}