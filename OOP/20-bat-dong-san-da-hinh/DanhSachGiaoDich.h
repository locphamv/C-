#pragma once
#include "GiaoDichCanHo.h"
#include "GiaoDichDat.h"
#include "GiaoDichNha.h"
#include <vector>

class DanhSachGiaoDich
{
private:
    std::vector<GiaoDich*> gd;
    int soDat, soNha, soCanHo;

public:
    DanhSachGiaoDich();
    ~DanhSachGiaoDich();

    void nhap();
    void xuatThongKe() const;
    void xuatGiaoDichNhaCaoNhat() const;
    void xuatDanhSachThang12Nam2024() const;
};