#include "Ngay.h"

int main()
{
    Date d1, d2;
    cout << "Nhap ngay 1: ";
    cin >> d1;
    cout << "Nhap ngay 2: ";
    cin >> d2;

    cout << "Ngay da nhap: " << d1;
    cout << "Ngay da nhap: " << d2;

    if (d1 > d2)
        cout << "Ngay 1 lon hon ngay 2";
    else
        cout << "Ngay 2 lon hon ngay 1";
}