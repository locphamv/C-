#include "cPhanSo.h"
#include <iostream>
using namespace std;

int cPhanSo::UCLN(int a, int b)
{
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;

    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    if (a == 0)
        return 1;
    return a;
}

void cPhanSo::GanGiaTri(int tu, int mau)
{
    tso = tu;

    if (mau == 0)
        mauso = 1;
    else
        mauso = mau;

    RutGon();
}

void cPhanSo::Nhap()
{
    cout << "Nhap tu so: ";
    cin >> tso;

    do
    {
        cout << "Nhap mau so: ";
        cin >> mauso;
        if (mauso == 0)
            cout << "Mau so phai khac 0. Nhap lai!\n";
    } while (mauso == 0);

    RutGon();
}

void cPhanSo::Xuat()
{
    if (mauso == 1)
        cout << tso;
    else
        cout << tso << "/" << mauso;
}

void cPhanSo::RutGon()
{
    if (mauso < 0)
    {
        tso = -tso;
        mauso = -mauso;
    }

    int u = UCLN(tso, mauso);
    tso = tso / u;
    mauso = mauso / u;
}

cPhanSo cPhanSo::Cong(cPhanSo b)
{
    cPhanSo kq;
    kq.tso = tso * b.mauso + b.tso * mauso;
    kq.mauso = mauso * b.mauso;
    kq.RutGon();
    return kq;
}

cPhanSo cPhanSo::Tru(cPhanSo b)
{
    cPhanSo kq;
    kq.tso = tso * b.mauso - b.tso * mauso;
    kq.mauso = mauso * b.mauso;
    kq.RutGon();
    return kq;
}

cPhanSo cPhanSo::Nhan(cPhanSo b)
{
    cPhanSo kq;
    kq.tso = tso * b.tso;
    kq.mauso = mauso * b.mauso;
    kq.RutGon();
    return kq;
}

cPhanSo cPhanSo::Chia(cPhanSo b)
{
    cPhanSo kq;
    kq.tso = tso * b.mauso;
    kq.mauso = mauso * b.tso;
    kq.RutGon();
    return kq;
}

int cPhanSo::TuSoBang0()
{
    if (tso == 0)
        return 1;
    return 0;
}
