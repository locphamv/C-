#include <iostream>
#include "string.h"
using namespace std;

int main()
{
    String a, b;

    cout << "Nhap chuoi a: ";
    a.Nhap();

    cout << "Nhap chuoi b: ";
    b.Nhap();

    cout << "\nChuoi a: ";
    a.Xuat();

    cout << "\nChuoi b: ";
    b.Xuat();

    cout << "\n\nChieu dai chuoi a: " << a.ChieuDai();
    cout << "\nChieu dai chuoi b: " << b.ChieuDai();

    a.Noi(b);
    cout << "\n\nSau khi noi a voi b: ";
    a.Xuat();

    a.DaoChuoi();
    cout << "\nSau khi dao chuoi a: ";
    a.Xuat();

    a.InHoa();
    cout << "\nSau khi doi sang chu hoa: ";
    a.Xuat();

    a.InThuong();
    cout << "\nSau khi doi sang chu thuong: ";
    a.Xuat();

    cout << endl;
    return 0;
}