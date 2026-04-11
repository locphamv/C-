#include <iostream>
#include <iomanip>
#include "vehicle.h"
using namespace std;

int main()
{
    Vehicle xe1("Nguyen Van An", "Xe may", 35000000, 90);
    Vehicle xe2("Tran Thi Binh", "Xe ga", 50000000, 150);
    Vehicle xe3;

    cout << "Nhap thong tin xe 3:\n";
    xe3.Nhap();

    cout << "\nBANG KE KHAI THONG TIN XE\n\n";

    cout << left << setw(20) << "Chu xe"
         << setw(15) << "Loai xe"
         << setw(15) << "Tri gia"
         << setw(15) << "Dung tich"
         << setw(15) << "Thue truoc ba"
         << endl;

    xe1.Xuat();
    xe2.Xuat();
    xe3.Xuat();

    return 0;
}