#include "Bo.h"
using namespace std;


Bo::Bo(int sl) : GiaSuc(sl)
{
}

string Bo::tiengKeu() const
{
    return "Bo... bo...";
}

int Bo::sinhCon() const
{
    int tongCon = 0;
    for (int i = 0; i < soLuong; i++)
    {
        tongCon += rand() % 3; // 0, 1, 2 con
    }
    return tongCon;
}

int Bo::choSua() const
{
    int tongSua = 0;
    for (int i = 0; i < soLuong; i++)
    {
        tongSua += rand() % 21; // 0 -> 20 lit
    }
    return tongSua;
}