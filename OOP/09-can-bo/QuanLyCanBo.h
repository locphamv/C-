#ifndef QUANLYCANBO_H
#define QUANLYCANBO_H

#include "CanBo.h"
#include <vector>

class QuanLyCanBo {
private:
    vector<CanBo*> danhSach;

public:
    QuanLyCanBo();
    ~QuanLyCanBo();

    void xoaDanhSachCu();

    void nhapDanhSach();
    void xuatDanhSach() const;

    void ghiFile() const;
    void docFile();

    void sapXepTheoLuong();
    void timCanBo() const;
    void suaCanBo();
    void tinhTongLuong() const;
};

#endif