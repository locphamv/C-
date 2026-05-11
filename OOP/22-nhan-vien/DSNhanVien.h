#pragma once
#include "LapTrinhVien.h"
#include "KiemChungVien.h"
#include <vector>
class DSNhanVien
{
    private:
    std::vector<NhanVien*> dsnv;

    public:
    void nhapDS();
    void xuatDS();
    void xuatBeHonTB();
    void xuatLuongMax();
    void xuatLuongMin();
    void xuatLapTrinhVienMax();
    void xuatKiemChuongVienMin();
    ~DSNhanVien();
};

