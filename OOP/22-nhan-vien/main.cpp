#include "DSNhanVien.h"

using namespace std;

int main()
{
    DSNhanVien ds;
    ds.nhapDS();
    ds.xuatDS();
    ds.xuatBeHonTB();
    ds.xuatLapTrinhVienMax();
    ds.xuatKiemChuongVienMin();
    ds.xuatLuongMax();
    ds.xuatLuongMin();

    return 0;
}