#include <iostream>
#include <cmath>
using namespace std;

struct Phanso
{
    long long tuso;
    long long mauso;
};

long long Ucln(Phanso a)
{
    long long tu = abs(a.tuso);
    long long mau = abs(a.mauso);
    while (mau != 0)
    {
        long long tmp = tu % mau;
        tu = mau;
        mau = tmp;
    }

    return tu;
}

int main()
{
    long long n;
    cin >> n;
    Phanso a;
    a.tuso = 2 * n;
    a.mauso = n + 1;
    long long uc = Ucln(a);
    a.tuso /= uc;
    a.mauso /= uc;
    if (a.mauso == 1)
    {
        cout << a.tuso;
        return 0;
    }
    cout << a.tuso << "/" << a.mauso;
    return 0;
}