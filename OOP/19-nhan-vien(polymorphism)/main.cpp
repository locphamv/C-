#include "DanhSachNhanVien.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << fixed << setprecision(0);

    DanhSachNhanVien ds;
    ds.nhap();
    ds.xuat();

    cout << "\nTong luong cong ty phai tra: " << ds.tongLuong() << endl;
    ds.xuatNhanVienSanXuatLuongThapNhat();
    ds.xuatNhanVienVanPhongLonTuoiNhat();

    return 0;
}