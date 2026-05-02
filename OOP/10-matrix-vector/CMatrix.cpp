#include "CMatrix.h"

CMatrix::CMatrix(int dong, int cot) : soDong(dong), soCot(cot), a(dong, vector<double>(cot, 0))
{
}

int CMatrix::laySoDong() const
{
    return soDong;
}

int CMatrix::laySoCot() const
{
    return soCot;
}

double CMatrix::layPhanTu(int i, int j) const
{
    if (i >= 0 && i < soDong && j >= 0 && j < soCot)
        return a[i][j];
    return 0;
}

void CMatrix::ganPhanTu(int i, int j, double value)
{
    if (i >= 0 && i < soDong && j >= 0 && j < soCot)
        a[i][j] = value;
}

CMatrix CMatrix::operator+(const CMatrix& other) const
{
    if (soDong != other.soDong || soCot != other.soCot)
    {
        cout << "Khong cong duoc hai ma tran khac kich thuoc!" << endl;
        return CMatrix();
    }

    CMatrix kq(soDong, soCot);

    for (int i = 0; i < soDong; i++)
    {
        for (int j = 0; j < soCot; j++)
        {
            kq.a[i][j] = a[i][j] + other.a[i][j];
        }
    }

    return kq;
}

CMatrix CMatrix::operator-(const CMatrix& other) const
{
    if (soDong != other.soDong || soCot != other.soCot)
    {
        cout << "Khong tru duoc hai ma tran khac kich thuoc!" << endl;
        return CMatrix();
    }

    CMatrix kq(soDong, soCot);

    for (int i = 0; i < soDong; i++)
    {
        for (int j = 0; j < soCot; j++)
        {
            kq.a[i][j] = a[i][j] - other.a[i][j];
        }
    }

    return kq;
}

void CMatrix::nhap(istream& is)
{
    cout << "Nhap so dong: ";
    is >> soDong;
    cout << "Nhap so cot: ";
    is >> soCot;

    if (soDong < 0) soDong = 0;
    if (soCot < 0) soCot = 0;

    a.assign(soDong, vector<double>(soCot, 0));

    for (int i = 0; i < soDong; i++)
    {
        for (int j = 0; j < soCot; j++)
        {
            cout << "Nhap phan tu [" << i << "][" << j << "]: ";
            is >> a[i][j];
        }
    }
}

void CMatrix::xuat(ostream& os) const
{
    for (int i = 0; i < soDong; i++)
    {
        for (int j = 0; j < soCot; j++)
        {
            os << a[i][j] << "\t";
        }
        os << endl;
    }
}

istream& operator>>(istream& is, CMatrix& m)
{
    m.nhap(is);
    return is;
}

ostream& operator<<(ostream& os, const CMatrix& m)
{
    m.xuat(os);
    return os;
}

CVector nhan(const CMatrix& m, const CVector& v)
{
    if (m.laySoCot() != v.soChieu())
    {
        cout << "Khong nhan duoc ma tran voi vector!" << endl;
        return CVector();
    }

    CVector kq(m.laySoDong());

    for (int i = 0; i < m.laySoDong(); i++)
    {
        double tong = 0;
        for (int j = 0; j < m.laySoCot(); j++)
        {
            tong += m.layPhanTu(i, j) * v.layPhanTu(j);
        }
        kq.ganPhanTu(i, tong);
    }

    return kq;
}

CMatrix nhan(const CMatrix& a, const CMatrix& b)
{
    if (a.laySoCot() != b.laySoDong())
    {
        cout << "Khong nhan duoc hai ma tran nay!" << endl;
        return CMatrix();
    }

    CMatrix kq(a.laySoDong(), b.laySoCot());

    for (int i = 0; i < a.laySoDong(); i++)
    {
        for (int j = 0; j < b.laySoCot(); j++)
        {
            double tong = 0;
            for (int k = 0; k < a.laySoCot(); k++)
            {
                tong += a.layPhanTu(i, k) * b.layPhanTu(k, j);
            }
            kq.ganPhanTu(i, j, tong);
        }
    }

    return kq;
}