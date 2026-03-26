#pragma once

class cDiem
{
private:
    float x;
    float y;

public:
    cDiem();
    cDiem(float hx, float ty);
    void thietLap(float hx, float ty);
    void thayDoi(float hx, float ty);

    float layHoanhDo();
    float layTungDo();

    void datHoanhDo(float hx);
    void datTungDo(float ty);

    void tinhTien(float a, float b);
    void nhap();
    void xuat();
};
