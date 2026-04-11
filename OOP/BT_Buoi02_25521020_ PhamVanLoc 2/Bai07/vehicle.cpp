#include "vehicle.h"
#include <iostream>
#include <iomanip>
using namespace std;

Vehicle::Vehicle()
{
    chuXe = "";
    loaiXe = "";
    triGiaXe = 0;
    dungTichXylanh = 0;
}

Vehicle::Vehicle(string cx, string lx, float tg, int dt)
{
    chuXe = cx;
    loaiXe = lx;

    if (tg >= 0)
        triGiaXe = tg;
    else
        triGiaXe = 0;

    if (dt >= 0)
        dungTichXylanh = dt;
    else
        dungTichXylanh = 0;
}

void Vehicle::DatChuXe(string cx)
{
    chuXe = cx;
}

void Vehicle::DatLoaiXe(string lx)
{
    loaiXe = lx;
}

void Vehicle::DatTriGiaXe(float tg)
{
    if (tg >= 0)
        triGiaXe = tg;
}

void Vehicle::DatDungTichXylanh(int dt)
{
    if (dt >= 0)
        dungTichXylanh = dt;
}

string Vehicle::LayChuXe()
{
    return chuXe;
}

string Vehicle::LayLoaiXe()
{
    return loaiXe;
}

float Vehicle::LayTriGiaXe()
{
    return triGiaXe;
}

int Vehicle::LayDungTichXylanh()
{
    return dungTichXylanh;
}

void Vehicle::Nhap()
{
    cin.ignore();

    cout << "Nhap chu xe: ";
    getline(cin, chuXe);

    cout << "Nhap loai xe: ";
    getline(cin, loaiXe);

    do
    {
        cout << "Nhap tri gia xe: ";
        cin >> triGiaXe;
        if (triGiaXe < 0)
            cout << "Tri gia xe phai >= 0. Nhap lai!\n";
    } while (triGiaXe < 0);

    do
    {
        cout << "Nhap dung tich xylanh: ";
        cin >> dungTichXylanh;
        if (dungTichXylanh < 0)
            cout << "Dung tich xylanh phai >= 0. Nhap lai!\n";
    } while (dungTichXylanh < 0);
}

float Vehicle::TinhThueTruocBa()
{
    if (dungTichXylanh < 100)
        return triGiaXe * 0.01f;
    if (dungTichXylanh <= 200)
        return triGiaXe * 0.03f;
    return triGiaXe * 0.05f;
}

void Vehicle::Xuat()
{
    cout << left << setw(20) << chuXe
         << setw(15) << loaiXe
         << setw(15) << fixed << setprecision(0) << triGiaXe
         << setw(15) << dungTichXylanh
         << setw(15) << fixed << setprecision(0) << TinhThueTruocBa()
         << endl;
}