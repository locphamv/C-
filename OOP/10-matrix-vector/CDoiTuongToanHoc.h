#pragma once
#include <iostream>
using namespace std;

class CDoiTuongToanHoc
{
public:
    virtual void nhap(istream& is) = 0;
    virtual void xuat(ostream& os) const = 0;
    virtual ~CDoiTuongToanHoc() {}
};