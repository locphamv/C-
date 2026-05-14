#pragma once
#include "Bo.h"
#include "Cuu.h"
#include "De.h"
#include <vector>

class DSGiaSuc
{
    private:
    vector<GiaSuc*> ds;
    public:
    void nhap();
    void giaSucKeu();
    void sauSinhVaChoSua();
    ~DSGiaSuc();
};