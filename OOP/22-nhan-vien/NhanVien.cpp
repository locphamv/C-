#include "NhanVien.h"
using namespace std;

void NhanVien::nhap()
{
    cout << "Nhap ma nhan vien: ";
    cin >> ma;
    cout << "Nhap ho va ten: ";
    getline(cin >> ws, ten);
    cout << "Nhap tuoi: ";
    cin >> tuoi;
    cout << "Nhap so dien thoai";
    cin >> sdt;
    cout << "Nhap email: ";
    cin >> email;
    cout << "Nhap luong co ban: ";
    cin >> luongCB;
}

void NhanVien::xuat() const
{
    cout << "Ma nhan vien: " << ma << endl;
    cout << "Ho va ten: " << ten << endl;
    cout << "Tuoi: " << tuoi << endl;
    cout << "So dien thoai: " << sdt << endl;
    cout << "Email: " << email << endl;
    cout << "Luong co ban: " << luongCB << endl;
}