#include "cDate.h"
#include <iostream>
using namespace std;

cDate::cDate()
{
    ngay = 1;
    thang = 1;
    nam = 2000;
}

int cDate::SoNgayTrongThang(int t, int n)
{
    if (t == 1 || t == 3 || t == 5 || t == 7 || t == 8 || t == 10 || t == 12)
        return 31;

    if (t == 4 || t == 6 || t == 9 || t == 11)
        return 30;

    if (t == 2)
    {
        if ((n % 400 == 0) || (n % 4 == 0 && n % 100 != 0))
            return 29;
        return 28;
    }

    return 30;
}

void cDate::ChuanHoa()
{
    while (thang > 12)
    {
        thang = thang - 12;
        nam++;
    }

    while (thang < 1)
    {
        thang = thang + 12;
        nam--;
    }

    while (ngay > SoNgayTrongThang(thang, nam))
    {
        ngay = ngay - SoNgayTrongThang(thang, nam);
        thang++;

        if (thang > 12)
        {
            thang = 1;
            nam++;
        }
    }

    while (ngay < 1)
    {
        thang--;

        if (thang < 1)
        {
            thang = 12;
            nam--;
        }

        ngay = ngay + SoNgayTrongThang(thang, nam);
    }

    if (ngay > SoNgayTrongThang(thang, nam))
        ngay = SoNgayTrongThang(thang, nam);
}

void cDate::Nhap()
{
    cout << "Nhap ngay: ";
    cin >> ngay;
    cout << "Nhap thang: ";
    cin >> thang;
    cout << "Nhap nam: ";
    cin >> nam;
    ChuanHoa();
}

void cDate::Xuat()
{
    cout << ngay << "/" << thang << "/" << nam;
}

void cDate::ThietLap(int d, int m, int y)
{
    ngay = d;
    thang = m;
    nam = y;
    ChuanHoa();
}

void cDate::DatNgay(int d)
{
    ngay = d;
    ChuanHoa();
}

void cDate::DatThang(int m)
{
    thang = m;
    ChuanHoa();
}

void cDate::DatNam(int y)
{
    nam = y;
    ChuanHoa();
}

int cDate::LayNgay()
{
    return ngay;
}

int cDate::LayThang()
{
    return thang;
}

int cDate::LayNam()
{
    return nam;
}

int cDate::LaNamNhuan()
{
    if ((nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0))
        return 1;
    return 0;
}

string cDate::ThuTrongTuan()
{
    int y = nam;
    int m = thang;
    int d = ngay;

    int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

    if (m < 3)
        y = y - 1;

    int thu = (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;

    if (thu == 0)
        return "Chu Nhat";
    if (thu == 1)
        return "Thu Hai";
    if (thu == 2)
        return "Thu Ba";
    if (thu == 3)
        return "Thu Tu";
    if (thu == 4)
        return "Thu Nam";
    if (thu == 5)
        return "Thu Sau";
    return "Thu Bay";
}

void cDate::TangNgay(int d)
{
    ngay = ngay + d;
    ChuanHoa();
}

void cDate::GiamNgay(int d)
{
    ngay = ngay - d;
    ChuanHoa();
}

void cDate::TangThang(int m)
{
    thang = thang + m;
    ChuanHoa();
    if (ngay > SoNgayTrongThang(thang, nam))
        ngay = SoNgayTrongThang(thang, nam);
}

void cDate::GiamThang(int m)
{
    thang = thang - m;
    ChuanHoa();
    if (ngay > SoNgayTrongThang(thang, nam))
        ngay = SoNgayTrongThang(thang, nam);
}

void cDate::TangNam(int y)
{
    nam = nam + y;
    if (ngay > SoNgayTrongThang(thang, nam))
        ngay = SoNgayTrongThang(thang, nam);
    ChuanHoa();
}

void cDate::GiamNam(int y)
{
    nam = nam - y;
    if (ngay > SoNgayTrongThang(thang, nam))
        ngay = SoNgayTrongThang(thang, nam);
    ChuanHoa();
}