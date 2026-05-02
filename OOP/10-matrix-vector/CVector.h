#pragma once
#include <iostream>
#include <vector>
#include "CDoiTuongToanHoc.h"
using namespace std;

class CVector : public CDoiTuongToanHoc
{
private:
    vector<double> phanTu;

public:
    CVector(int n = 0);

    int soChieu() const;
    double layPhanTu(int i) const;
    void ganPhanTu(int i, double value);

    CVector operator+(const CVector& other) const;
    CVector operator-(const CVector& other) const;

    void nhap(istream& is) override;
    void xuat(ostream& os) const override;

    friend istream& operator>>(istream& is, CVector& v);
    friend ostream& operator<<(ostream& os, const CVector& v);
};