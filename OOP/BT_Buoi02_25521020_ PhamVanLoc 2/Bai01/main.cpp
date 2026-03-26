#include <iostream>
#include "cPhanSo.h"
using namespace std;

int main()
{
    cPhanSo ps1, ps2, tong, hieu, tich, thuong;

    cout << "Nhap phan so thu 1:\n";
    ps1.Nhap();

    cout << "Nhap phan so thu 2:\n";
    ps2.Nhap();

    tong = ps1.Cong(ps2);

    hieu = ps1.Tru(ps2);

    tich = ps1.Nhan(ps2);

    cout << "\nTong: ";
    tong.Xuat();

    cout << "\nHieu: ";
    hieu.Xuat();

    cout << "\nTich: ";
    tich.Xuat();

    cout << "\nThuong: ";
    if (ps2.TuSoBang0() == 1)
        cout << "Khong chia duoc";
    else
    {
        thuong = ps1.Chia(ps2);
        thuong.Xuat();
    }

    cout << endl;
    return 0;
}
