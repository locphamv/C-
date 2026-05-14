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
