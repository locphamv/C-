#include <iostream>
#include "cSoPhuc.h"
using namespace std;

int main()
{
    cSoPhuc A, B;
    cSoPhuc tong, hieu, tich, thuong;

    cout << "Nhap so phuc A:\n";
    A.nhap();

    cout << "Nhap so phuc B:\n";
    B.nhap();

    tong = A + B;
    hieu = A - B;
    tich = A * B;

    cout << "\nA + B = ";
    tong.xuat();

    cout << "\nA - B = ";
    hieu.xuat();

    cout << "\nA * B = ";
    tich.xuat();

    cout << "\nA / B = ";
    if (B.laSo0() == 1)
        cout << "Khong chia duoc";
    else
    {
        thuong = A / B;
        thuong.xuat();
    }

    cout << endl;
    return 0;
}