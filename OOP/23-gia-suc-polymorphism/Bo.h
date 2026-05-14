#pragma once
#include "GiaSuc.h"

class Bo : public GiaSuc
{
  public:
    Bo(int sl = 0);

    string tiengKeu() const override;
    int sinhCon() const override;
    int choSua() const override;
};