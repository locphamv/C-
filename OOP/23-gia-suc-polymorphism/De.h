#pragma once
#include "GiaSuc.h"

class De : public GiaSuc
{
  public:
    De(int sl = 0);

    string tiengKeu() const override;
    int sinhCon() const override;
    int choSua() const override;
};