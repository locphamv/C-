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
}

void NhanVien::xuat() const
{
    cout << "Ho va ten: " << hoTen << endl;
    cout << "Ngay sinh: " << ngaySinh << endl;
}
