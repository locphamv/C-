#include <iostream>
#include "cDiem.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cDiem A;
    cDiem B(2, 3);

    cout << "Nhap diem A:\n";
    A.nhap();
    cout << "\nToa do diem A: ";
    A.xuat();
    cout << endl;

    cout << "\nToa do diem B: ";
    B.xuat();
    cout << endl;

    cout << "\nHoanh do diem A: " << A.layHoanhDo() << endl;
    cout << "\nTung do diem A: " << A.layTungDo() << endl;

    A.datHoanhDo(15);
    A.datTungDo(15);
    cout << "\n Diem A sau khi dat lai: ";
    A.xuat();
    cout << endl;

    A.tinhTien(10, 10);
    cout << "\n Diem A sau khi tinh tien: ";
    A.xuat();
    cout << endl;

    A.thayDoi(10, 10);
    cout << "\n Diem A sau khi thayDoi: ";
    A.xuat();
    cout << endl;

    return 0;
}