#include "Cuu.h"
using namespace std;

Cuu::Cuu(int sl) : GiaSuc(sl)
{
}

string Cuu::tiengKeu() const
{
    return "Be... be...";
}

int Cuu::sinhCon() const
{
    int tongCon = 0;
    for (int i = 0; i < soLuong; i++)
    {
        tongCon += rand() % 3;
    }
    return tongCon;
}

int Cuu::choSua() const
{
    int tongSua = 0;
    for (int i = 0; i < soLuong; i++)
    {
        tongSua += rand() % 6; // 0 -> 5 lit
    }
    return tongSua;
}