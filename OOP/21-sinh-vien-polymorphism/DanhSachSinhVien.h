#pragma once
#include "SinhVienCaoDang.h"
#include "SinhVienDaiHoc.h"
#include <vector>

class DanhSachSinhVien
{
private:
    std::vector<SinhVien*> sv;

public:
    ~DanhSachSinhVien();

    void nhap();
    void xuatDanhSach() const;
    void xuatDuDieuKien() const;
    void xuatKhongDuDieuKien() const;
    void xuatDaiHocDtbCaoNhat() const;
    void xuatCaoDangDtbCaoNhat() const;
    void xuatSoLuongKhongDuDieuKien() const;
};