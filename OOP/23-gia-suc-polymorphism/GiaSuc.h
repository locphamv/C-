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

    virtual string tiengKeu() const = 0;
    virtual int sinhCon() const = 0;
    virtual int choSua() const = 0;
    virtual ~GiaSuc() = default;
};
