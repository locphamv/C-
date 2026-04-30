#ifndef NHANVIENHANHCHINH_H
#define NHANVIENHANHCHINH_H

#include "CanBo.h"

class NhanVienHanhChinh : public CanBo {
private:
    string phongBan;
    string chucVu;
    int soNgayCong;

public:
    NhanVienHanhChinh();

    int tinhPhuCap() const;
    double tinhLuong() const override;

    void nhap() override;
    void xuat() const override;

    void ghiFile(ofstream& out) const override;
    void docFile(ifstream& in) override;
};

#endif