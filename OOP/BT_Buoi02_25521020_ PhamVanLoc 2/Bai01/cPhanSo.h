#pragma once

class cPhanSo
{
private:
    int tso;
    int mauso;

    int UCLN(int a, int b);

public:
    void GanGiaTri(int tu, int mau);
    void Nhap();
    void Xuat();
    void RutGon();

    cPhanSo Cong(cPhanSo b);
    cPhanSo operator+(cPhanSo b);
    cPhanSo Tru(cPhanSo b);
    cPhanSo Nhan(cPhanSo b);
    cPhanSo Chia(cPhanSo b);

    int TuSoBang0();
};
