#include "cThoiGian.h"
#include <iostream>
using namespace std;

cThoiGian::cThoiGian()
{
    gio = 0;
    phut = 0;
    giay = 0;
}

cThoiGian::cThoiGian(int g, int p, int s)
{
    gio = g;
    phut = p;
    giay = s;
    ChuanHoa();
}

void cThoiGian::ChuanHoa()
{
    while (giay >= 60)
    {
        giay = giay - 60;
        phut++;
    }

    while (giay < 0)
    {
        giay = giay + 60;
        phut--;
    }

    while (phut >= 60)
    {
        phut = phut - 60;
        gio++;
    }

    while (phut < 0)
    {
        phut = phut + 60;
        gio--;
    }

    while (gio >= 24)
        gio = gio - 24;
    while (gio < 0)
        gio = gio + 24;
}

void cThoiGian::nhap()
{
    cout << "Nhap gio: ";
    cin >> gio;
    cout << "Nhap phut: ";
    cin >> phut;
    cout << "Nhap giay: ";
    cin >> giay;
    ChuanHoa();
}

void cThoiGian::xuat()
{
    cout << gio << ":" << phut << ":" << giay;
}

void cThoiGian::ThietLap(int g, int p, int s)
{
    gio = g;
    phut = p;
    giay = s;
    ChuanHoa();
}

void cThoiGian::DatGio(int g)
{
    gio = g;
    ChuanHoa();
}

void cThoiGian::DatPhut(int p)
{
    phut = p;
    ChuanHoa();
}

void cThoiGian::DatGiay(int s)
{
    giay = s;
    ChuanHoa();
}

int cThoiGian::LayGio()
{
    return gio;
}

int cThoiGian::LayPhut()
{
    return phut;
}

int cThoiGian::LayGiay()
{
    return giay;
}

void cThoiGian::TangGio(int g)
{
    gio = gio + g;
    ChuanHoa();
}

void cThoiGian::TangPhut(int p)
{
    phut = phut + p;
    ChuanHoa();
}

void cThoiGian::TangGiay(int s)
{
    giay = giay + s;
    ChuanHoa();
}

void cThoiGian::GiamGio(int g)
{
    gio = gio - g;
    ChuanHoa();
}

void cThoiGian::GiamPhut(int p)
{
    phut = phut - p;
    ChuanHoa();
}

void cThoiGian::GiamGiay(int s)
{
    giay = giay - s;
    ChuanHoa();
}
