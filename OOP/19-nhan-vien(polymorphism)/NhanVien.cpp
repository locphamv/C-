#include "NhanVien.h"
using namespace std;

NhanVien::NhanVien() : hoTen(""), ngaySinh("")
{
}

void NhanVien::nhap()
{
    cout << "Nhap ho va ten: ";
    getline(cin >> ws, hoTen);
    cout << "Nhap ngay sinh: ";
    cin >> ngaySinh;
    chuanHoaNgay(ngaySinh);
}

void NhanVien::chuanHoaNgay(string &ngay)
{
    if (ngay.length() >= 3 && ngay[2] != '/')
        ngay = "0" + ngay;
    if (ngay.length() >= 6 && ngay[5] != '/')
        ngay.insert(3, "0");
}
void NhanVien::xuat() const
{
    cout << "Ho va ten: " << hoTen << endl;
    cout << "Ngay sinh: " << ngaySinh << endl;
}

string NhanVien::getNgaySinh() const
{
    return ngaySinh;
}