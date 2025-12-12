#include <iostream>
using namespace std;

struct DONTHUC
{
    float heso;
    int somu;
};
struct DATHUC
{
    int n;
    DONTHUC *list;
};

DATHUC *Nhap()
{
    DATHUC *d = new DATHUC;
    cin >> d->n;
    d->list = new DONTHUC[d->n];
    for (int i = 0; i < d->n; i++)
    {
        cin >> d->list[i].heso >> d->list[i].somu;
    }
    return d;
}

void HoanVi(DONTHUC &a, DONTHUC &b)
{
    DONTHUC temp = a;
    a = b;
    b = temp;
}

DATHUC RutGon(DATHUC raw)
{
    DATHUC result;
    result.list = new DONTHUC[raw.n];
    result.n = 0;
    for (int i = 0; i < raw.n; i++)
    {
        bool daCo = false;
        for (int j = 0; j < result.n; j++)
        {
            if (result.list[j].somu == raw.list[i].somu)
            {
                result.list[j].heso += raw.list[i].heso;
                daCo = true;
                break;
            }
        }

        if (!daCo)
        {
            result.list[result.n] = raw.list[i];
            result.n++;
        }
    }

    for (int i = 0; i < result.n - 1; i++)
    {
        for (int j = i + 1; j < result.n; j++)
        {
            if (result.list[i].somu < result.list[j].somu)
            {
                HoanVi(result.list[i], result.list[j]);
            }
        }
    }

    return result;
}
DATHUC Tong2DaThuc(DATHUC *a, DATHUC *b)
{
    DATHUC sum;
    sum.n = a->n + b->n;
    sum.list = new DONTHUC[sum.n];
    for (int i = 0; i < a->n; i++)
    {
        sum.list[i] = a->list[i];
    }
    for (int i = 0; i < b->n; i++)
    {
        sum.list[i + a->n] = b->list[i];
    }

    return RutGon(sum);
}
void Xuat(DATHUC a)
{
    bool isFirst = true;
    bool empty = true;
    for (int i = 0; i < a.n; i++)
    {
        float heso = a.list[i].heso;
        int somu = a.list[i].somu;

        if (heso == 0)
            continue;

        if (heso > 0)
        {
            if (!isFirst)
                cout << "+";
        }
        else
        {
            cout << "-";
        }

        float absHeso = abs(heso);

        if (absHeso != 1 || somu == 0)
        {
            cout << absHeso;
        }

        if (somu > 0)
        {
            cout << "x";
            if (somu != 1)
            {
                cout << "^" << somu;
            }
        }
        empty = false;
        isFirst = false;
    }
    if (empty)
    {
        cout << "0";
    }
}
int main()
{
    DATHUC *A, *B;
    A = Nhap();
    B = Nhap();
    cout << "Da thuc A: ";
    Xuat(*A);
    cout << "\nDa thuc B: ";
    Xuat(*B);
    cout << "\nA+B = ";
    Xuat(Tong2DaThuc(A, B));
    return 0;
}
