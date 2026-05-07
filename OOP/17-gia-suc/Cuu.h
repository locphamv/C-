#pragma once
#include"GiaSuc.h"

class Cuu : public GiaSuc
{
public:
    Cuu(int sl = 0);

    string tiengKeu() const;
    int sinhCon() const;
    int choSua() const;
};
