#include <iostream>
using namespace std;

struct PhanSo
{
    int tu;
    int mau;
};
void Nhap(PhanSo &p)
{
    cin >> p.tu >> p.mau;
}

PhanSo Nhap()
{
    PhanSo p;

    cin >> p.tu >> p.mau;

    return p;
}

int SoSanh(PhanSo p1, PhanSo p2)
{

    double gt1 = (double)p1.tu / p1.mau;
    double gt2 = (double)p2.tu / p2.mau;

    if (gt1 == gt2)
    {
        return 0;
    }
    if (gt1 > gt2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
int main()
{
    PhanSo a, b;
    Nhap(a);
    b = Nhap();
    int kq = SoSanh(a, b);

    if (kq == 0)
        std::cout << "Hai phan so bang nhau.";
    else if (kq > 0)
        std::cout << "Phan so thu nhat LON hon phan so thu hai.";
    else
        std::cout << "Phan so thu nhat NHO hon phan so thu hai.";
    return 0;
}