#include "ChuyenXeNgoaiThanh.h"

ChuyenXeNgoaiThanh::ChuyenXeNgoaiThanh() : ChuyenXe()
{
}

void ChuyenXeNgoaiThanh::nhap()
{
    ChuyenXe::nhap();
    cout << "Nhap noi den: ";
    getline(cin >> ws, noiDen);
    cout << "Nhap so ngay di: ";
    cin >> soNgayDi;
}

void ChuyenXeNgoaiThanh::xuat() const
{
    ChuyenXe::xuat();
    cout << "\nNoi den: " << noiDen;
    cout << "\nSo ngay di: " << soNgayDi;
}