#include "GiaoDich.h"
using namespace std;

GiaoDich::GiaoDich(string ma, string ngay, double gia, int so)
    : maGiaoDich(ma), ngayGiaoDich(ngay), donGia(gia), soLuong(so)
{
}

void GiaoDich::nhap()
{
    cout << "Nhap ma giao dich: ";
    cin >> maGiaoDich;
    cout << "Nhap ngay giao dich: ";
    cin >> ngayGiaoDich;
    cout << "Nhap don gia: ";
    cin >> donGia;
    cout << "Nhap so luong: ";
    cin >> soLuong;
}

void GiaoDich::xuat()
{
    cout << "Ma giao dich la: " << maGiaoDich << endl;
    cout << "Ngay giao dich la: " << ngayGiaoDich << endl;
    cout << "Don gia  la: " << donGia << endl;
    cout << "So luong giao dich la: " << soLuong << endl;
}

int GiaoDich::getSoLuong()
{
    return soLuong;
}

double GiaoDich::getDonGia()
{
    return donGia;
}