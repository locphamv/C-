#pragma once
#include "GiaSuc.h"


class Bo : public GiaSuc
{
public:
    Bo(int sl = 0);

    string tiengKeu() const;
    int sinhCon() const;
    int choSua() const;
};