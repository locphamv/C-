#include "NhanVienVanPhong.h"
using namespace std;

NhanVienVanPhong::NhanVienVanPhong() : NhanVien(), soNgayLam(0)
{
}
void NhanVienVanPhong::nhap()
{
    NhanVien::nhap();
    cout << "Nhap so ngay lam viec: ";
    cin >> soNgayLam;
}

void NhanVienVanPhong::xuat() const
{
    NhanVien::xuat();
    cout << "So ngay lam viec: " << soNgayLam<<endl;
    cout << "Luong = "<<tinhLuong()<<endl;
}

double NhanVienVanPhong::tinhLuong() const
{
    return 100000*soNgayLam;
}