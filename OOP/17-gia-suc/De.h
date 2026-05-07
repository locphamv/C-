#pragma once
#include "GiaSuc.h"

class De : public GiaSuc
{
  public:
    De(int sl = 0);

    string tiengKeu() const;
    int sinhCon() const;
    int choSua() const;
};