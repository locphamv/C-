#include <iostream>
#include "cDate.h"
using namespace std;

int main()
{
    cDate a;
    int x;

    cout << "Nhap ngay thang nam ban dau:\n";
    a.Nhap();

    cout << "\nNgay thang nam vua nhap: ";
    a.Xuat();

    if (a.LaNamNhuan() == 1)
        cout << "\nNam nay la nam nhuan";
    else
        cout << "\nNam nay khong phai nam nhuan";

    cout << "\nThu trong tuan: " << a.ThuTrongTuan();

    cout << "\n\nNhap so ngay can tang: ";
    cin >> x;
    a.TangNgay(x);
    cout << "Sau khi tang ngay: ";
    a.Xuat();

    cout << "\nNhap so thang can tang: ";
    cin >> x;
    a.TangThang(x);
    cout << "Sau khi tang thang: ";
    a.Xuat();

    cout << "\nNhap so nam can tang: ";
    cin >> x;
    a.TangNam(x);
    cout << "Sau khi tang nam: ";
    a.Xuat();

    cout << "\n\nNhap so ngay can giam: ";
    cin >> x;
    a.GiamNgay(x);
    cout << "Sau khi giam ngay: ";
    a.Xuat();

    cout << "\nNhap so thang can giam: ";
    cin >> x;
    a.GiamThang(x);
    cout << "Sau khi giam thang: ";
    a.Xuat();

    cout << "\nNhap so nam can giam: ";
    cin >> x;
    a.GiamNam(x);
    cout << "Sau khi giam nam: ";
    a.Xuat();

    cout << "\n\nNgay hien tai: " << a.LayNgay();
    cout << "\nThang hien tai: " << a.LayThang();
    cout << "\nNam hien tai: " << a.LayNam();

    cout << "\n";
    return 0;
}