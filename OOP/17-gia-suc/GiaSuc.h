#pragma once
#include <iostream>
#include <string>
using namespace std;

class GiaSuc
{
protected:
    int soLuong;

public:
    GiaSuc(int sl = 0);

    void setSoLuong(int sl);
    int getSoLuong() const;

    virtual string tiengKeu() const;
    virtual int sinhCon() const;
    virtual int choSua() const;
};

