#pragma once
#include "NhanVienSanXuat.h"
#include "NhanVienVanPhong.h"
#include <vector>
#include <string>

class DanhSachNhanVien
{
private:
    std::vector<NhanVien*> ds;

    bool ngaySinhNhoHon(const std::string& a, const std::string& b) const;

public:
    ~DanhSachNhanVien();

    void nhap();
    void xuat() const;
    double tongLuong() const;
    void xuatNhanVienSanXuatLuongThapNhat() const;
    void xuatNhanVienVanPhongLonTuoiNhat() const;
};