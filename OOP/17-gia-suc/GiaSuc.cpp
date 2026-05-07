#include "GiaSuc.h"
#include <cstdlib>

GiaSuc::GiaSuc(int sl) : soLuong(sl)
{
}

void GiaSuc::setSoLuong(int sl)
{
    soLuong = sl;
}

int GiaSuc::getSoLuong() const
{
    return soLuong;
}

string GiaSuc::tiengKeu() const
{
    return "";
}

int GiaSuc::sinhCon() const
{
    return 0;
}

int GiaSuc::choSua() const
{
    return 0;
}


