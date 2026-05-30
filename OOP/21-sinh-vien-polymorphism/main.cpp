#include "DanhSachSinhVien.h"

int main()
{
    DanhSachSinhVien ds;
    ds.nhap();
    ds.xuatDanhSach();
    ds.xuatDuDieuKien();
    ds.xuatKhongDuDieuKien();
    ds.xuatDaiHocDtbCaoNhat();
    ds.xuatCaoDangDtbCaoNhat();
    ds.xuatSoLuongKhongDuDieuKien();
    return 0;
}