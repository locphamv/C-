#ifndef GIANGVIEN_H
#define GIANGVIEN_H

#include "CanBo.h"

class GiangVien : public CanBo {
private:
    string khoa;
    string trinhDo;
    int soTietDay;

public:
    GiangVien();

    int tinhPhuCap() const;
    double tinhLuong() const override;

    void nhap() override;
    void xuat() const override;

    void ghiFile(ofstream& out) const override;
    void docFile(ifstream& in) override;
};

#endif