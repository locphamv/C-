#include "De.h"
using namespace std;

De::De(int sl) : GiaSuc(sl)
{
}

string De::tiengKeu() const
{
    return "De... de...";
}

int De::sinhCon() const
{
    int tongCon = 0;
    for (int i = 0; i < soLuong; i++)
    {
        tongCon += rand() % 3;
    }
    return tongCon;
}

int De::choSua() const
{
    int tongSua = 0;
    for (int i = 0; i < soLuong; i++)
    {
        tongSua += rand() % 11; // 0 -> 10 lit
    }
    return tongSua;
}