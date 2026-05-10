#include "GiaoDich.h"
using namespace std;

GiaoDich::GiaoDich(string ma, string ngay, double donGia, double dienTich)
    : ma(ma), ngay(ngay), donGia(donGia), dienTich(dienTich)
{
}

void GiaoDich::nhap()
{
    cout << "Nhap ma giao dich: ";
    cin >> ma;
    cout << "Nhap ngay giao dich(dd/mm/yyyy): ";
    cin >> ngay;
    cout << "Nhap don gia: ";
    cin >> donGia;
    cout << "Nhap dien tich: ";
    cin >> dienTich;
}

void GiaoDich::xuat() const
{
    cout << "Ma giao dich: " << ma << endl;
    cout << "Ngay giao dich: " << ngay << endl;
    cout << "Don gia: " << donGia << endl;
    cout << "Dien tich: " << dienTich << endl;
}

double GiaoDich::getDonGia() const
{
    return donGia;
}
double GiaoDich::getDienTich() const
{
    return dienTich;
}

string GiaoDich::getThangNgay() const
{
    return ngay.substr(3, 7);
}
