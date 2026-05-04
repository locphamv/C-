#include "Sach.h"
using namespace std;

Sach::Sach()
{
    ma = ngayNhap = nhaXuatBan = "";
    donGia = soLuong = 0;
}

void Sach::nhap()
{
    cout << "Nhap ma sach: ";
    cin >> ma;
    cout << "Ngay nhap sach: ";
    cin >> ngayNhap;
    cout << "Nhap nha xuat ban: ";
    getline(cin >> ws, nhaXuatBan);
    cout << "Nhap don gia: ";
    cin >> donGia;
    cout << "So luong: ";
    cin >> soLuong;
}

void Sach::xuat()
{
    cout << "Ma sach: " << ma << endl;
    cout << "Ngay nhap sach: " << ngayNhap << endl;
    cout << "Nha xuat ban: " << nhaXuatBan << endl;
    cout << "Don gia: " << donGia << endl;
    cout << "So luong: " << soLuong << endl;
}

int Sach::getSoLuong()
{
    return soLuong;
}

double Sach::getDonGia()
{
    return donGia;
}

string Sach::getNxb()
{
    return nhaXuatBan;
}