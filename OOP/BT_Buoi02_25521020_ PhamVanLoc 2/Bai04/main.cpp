#include <iostream>
#include "cThoiGian.h"
using namespace std;

int main()
{
    cThoiGian t;
    int x;

    cout << "Nhap thoi gian ban dau:\n";
    t.nhap();

    cout << "\nThoi gian vua nhap: ";
    t.xuat();

    cout << "\n\nNhap so gio can tang: ";
    cin >> x;
    t.TangGio(x);
    cout << "Sau khi tang gio: ";
    t.xuat();

    cout << "\nNhap so phut can tang: ";
    cin >> x;
    t.TangPhut(x);
    cout << "Sau khi tang phut: ";
    t.xuat();

    cout << "\nNhap so giay can tang: ";
    cin >> x;
    t.TangGiay(x);
    cout << "Sau khi tang giay: ";
    t.xuat();

    cout << "\n\nNhap so gio can giam: ";
    cin >> x;
    t.GiamGio(x);
    cout << "Sau khi giam gio: ";
    t.xuat();

    cout << "\nNhap so phut can giam: ";
    cin >> x;
    t.GiamPhut(x);
    cout << "Sau khi giam phut: ";
    t.xuat();

    cout << "\nNhap so giay can giam: ";
    cin >> x;
    t.GiamGiay(x);
    cout << "Sau khi giam giay: ";
    t.xuat();

    cout << "\n\nGio hien tai: " << t.LayGio();
    cout << "\nPhut hien tai: " << t.LayPhut();
    cout << "\nGiay hien tai: " << t.LayGiay();

    cout << "\n";
    return 0;
}
