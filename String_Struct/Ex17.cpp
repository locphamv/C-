#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct DONTHUC
{
    float heso;
    int somu;
};
struct DATHUC
{
    int n;
    DONTHUC list[105];
};

DATHUC *Nhap()
{
    DATHUC *a = new DATHUC;
    cin >> a->n;
    for (int i = 0; i < a->n; i++)
    {
        cin >> a->list[i].heso >> a->list[i].somu;
    }
    return a;
}

double TinhDaThuc(DATHUC a, float x)
{
    double kq = 0;
    for (int i = 0; i < a.n; i++)
    {
        kq += a.list[i].heso * pow(x, a.list[i].somu);
    }
    return kq;
}
void Xuat(DATHUC a)
{
    bool isFirst = true;
    bool empty = true;
    for (int i = 0; i < a.n; i++)
    {
        float hesomoi = a.list[i].heso;
        int somumoi = a.list[i].somu;
        if (hesomoi == 0)
        {
            continue;
        }
        if (hesomoi > 0)
        {
            if (!isFirst)
            {
                cout << "+";
            }
        }
        if (hesomoi < 0)
        {
            cout << "-";
        }
        float hesoabs = abs(hesomoi);
        if (hesoabs != 1 || somumoi == 0)
        {
            cout << hesoabs;
        }

        if (somumoi > 0)
        {
            cout << "x";
            if (somumoi != 1)
            {
                cout << "^" << somumoi;
            }
        }
        isFirst = false;
        empty = false;
    }
    if (empty)
    {
        cout << 0;
    }
}

int main()
{
    DATHUC *B;
    B = Nhap();
    cout << "Da thuc vua nhap la: ";
    Xuat(*B);
    double x;
    cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(*B, x);
    return 0;
}
