// PhanSo.h
#pragma once
#include <iostream>
using namespace std;

class PhanSo {
private:
    long long Tu, Mau;

    void chuanHoa();

public:
    PhanSo(long long tu = 0, long long mau = 1);

    PhanSo operator+(const PhanSo& other) const;

    friend istream& operator>>(istream& is, PhanSo& ps);
    friend ostream& operator<<(ostream& os, const PhanSo& ps);
};