#pragma once
#include "GiaSuc.h"

class Cuu : public GiaSuc
{
  public:
    Cuu(int sl = 0);

    string tiengKeu() const override;
    int sinhCon() const override;
    int choSua() const override;
};
