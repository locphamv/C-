#pragma once
#include <iostream>
#include <vector>
#include "CDoiTuongToanHoc.h"
#include "CVector.h"
using namespace std;

class CMatrix : public CDoiTuongToanHoc
{
private:
    int soDong;
    int soCot;
    vector<vector<double>> a;

public:
    CMatrix(int dong = 0, int cot = 0);

    int laySoDong() const;
    int laySoCot() const;
    double layPhanTu(int i, int j) const;
    void ganPhanTu(int i, int j, double value);

    CMatrix operator+(const CMatrix& other) const;
    CMatrix operator-(const CMatrix& other) const;

    void nhap(istream& is) override;
    void xuat(ostream& os) const override;

    friend istream& operator>>(istream& is, CMatrix& m);
    friend ostream& operator<<(ostream& os, const CMatrix& m);
};

CVector nhan(const CMatrix& m, const CVector& v);
CMatrix nhan(const CMatrix& a, const CMatrix& b);