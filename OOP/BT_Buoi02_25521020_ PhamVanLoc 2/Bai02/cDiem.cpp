#include "cDiem.h"
#include <iostream>

using namespace std;

cDiem::cDiem()
{
    x = 0;
    y = 0;
}
cDiem::cDiem(float hx, float ty)
{
    x = hx;
    y = ty;
}
void cDiem::thietLap(float hx, float ty)
{
    x = hx;
    y = ty;
}
void cDiem::thayDoi(float hx, float ty)
{
    x = hx;
    y = ty;
}

float cDiem::layHoanhDo()
{
    return x;
}
float cDiem::layTungDo()
{
    return y;
}
void cDiem::datHoanhDo(float hx)
{
    x = hx;
}
void cDiem::datTungDo(float ty)
{
    y = ty;
}

void cDiem::tinhTien(float a, float b)
{
    x = x + a;
    y = y + a;
}
void cDiem::nhap()
{
    cout << "Nhap hoanh do: ";
    cin >> x;
    cout << "Nhap tung do: ";
    cin >> y;
}
void cDiem::xuat()
{
    cout << "(" << x << ", " << y << ")";
}
