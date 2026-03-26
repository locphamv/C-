#pragma once
class cSoPhuc
{
private:
    float phanThuc;
    float phanAo;

public:
    cSoPhuc();
    cSoPhuc(float phanThuc, float phanAo);
    void ganGiaTri(float phanThuc, float phanAo);
    void nhap();
    void xuat();

    cSoPhuc operator+(cSoPhuc b);
    cSoPhuc operator-(cSoPhuc b);
    cSoPhuc operator*(cSoPhuc b);
    cSoPhuc operator/(cSoPhuc b);

    int laSo0();
};