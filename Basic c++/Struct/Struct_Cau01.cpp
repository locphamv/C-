#include <iostream>
#include <cmath>
using namespace std;

struct DonThuc
{
    float heSo;
    int soMu;
};

void nhapDonThuc(DonThuc &dt)
{
    cout << "Nhap He So: ";
    cin >> dt.heSo;
    cout << "Nhap So Mu: ";
    cin >> dt.soMu;
}

void xuatDonThuc(DonThuc dt)
{
    if (dt.heSo == 0)
    {
        cout << 0;
        return;
    }
    if (dt.soMu == 0)
    {
        cout << dt.heSo;
        return;
    }

    if (dt.heSo == -1)
    {
        cout << "-";
    }
    else if (dt.heSo != 1)
    {
        cout << dt.heSo;
    }
    cout << "x";
    if (dt.soMu != 1)
    {
        cout << "^" << dt.soMu;
    }
}

void xuatPhepCong(DonThuc dt1, DonThuc dt2)
{
    if (dt1.soMu == dt2.soMu)
    {
        DonThuc ketQua;
        ketQua.heSo = dt1.heSo + dt2.heSo;
        ketQua.soMu = dt1.soMu;
        xuatDonThuc(ketQua);
    }

    else
    {
        xuatDonThuc(dt1);
        if (dt2.heSo >= 0)
        {
            cout << " + ";
            xuatDonThuc(dt2);
        }
        else
        {
            cout << " ";
            xuatDonThuc(dt2);
        }
    }
}
void xuatPhepTru(DonThuc dt1, DonThuc dt2)
{
    if (dt1.soMu == dt2.soMu)
    {
        DonThuc ketQua;
        ketQua.heSo = dt1.heSo - dt2.heSo;
        ketQua.soMu = dt1.soMu;
        xuatDonThuc(ketQua);
    }
    else
    {
        xuatDonThuc(dt1);
        cout << "-(";
        xuatDonThuc(dt2);
        cout << ")";
    }
}

DonThuc tich(DonThuc dt1, DonThuc dt2)
{
    DonThuc ketQua;
    ketQua.heSo = dt1.heSo * dt2.heSo;
    ketQua.soMu = dt1.soMu + dt2.soMu;
    return ketQua;
}

DonThuc thuong(DonThuc dt1, DonThuc dt2)
{
    DonThuc ketQua;
    if (dt2.heSo == 0)
    {
        ketQua.heSo = 0;
        ketQua.soMu = 0;
    }
    else
    {
        ketQua.heSo = dt1.heSo / dt2.heSo;
        ketQua.soMu = dt1.soMu - dt2.soMu;
    }
    return ketQua;
}

DonThuc daoHam(DonThuc dt)
{
    DonThuc ketQua;
    if (dt.soMu == 0)
    {
        ketQua.heSo = 0;
        ketQua.soMu = 0;
    }
    else
    {
        ketQua.heSo = dt.heSo * dt.soMu;
        ketQua.soMu = dt.soMu - 1;
    }
    return ketQua;
}

float tinhGiaTri(DonThuc dt, float x)
{
    return dt.heSo * pow(x, dt.soMu);
}

int main()
{
    DonThuc dt1, dt2;

    cout << "Nhap don thuc 1:" << endl;
    nhapDonThuc(dt1);
    cout << "> Don thuc 1 la: ";
    xuatDonThuc(dt1);
    cout << endl;

    cout << "Nhap don thuc 2: " << endl;
    nhapDonThuc(dt2);
    cout << "> Don thuc 2 la: ";
    xuatDonThuc(dt2);
    cout << endl;

    cout << "Ket qua phep cong: ";
    xuatPhepCong(dt1, dt2);

    cout << "\nKet qua phep tru: ";
    xuatPhepTru(dt1, dt2);

    cout << "\nTich 2 don thuc la: ";
    xuatDonThuc(tich(dt1, dt2));

    cout << "\nThuong cua don thuc 1 chia cho don thuc 2 la: ";
    if (dt2.heSo == 0)
        cout << "Khong the chia (he so bang 0)";
    else
        xuatDonThuc(thuong(dt1, dt2));

    cout << "\n> Dao ham cap 1 cua dt1 = ";
    xuatDonThuc(daoHam(dt1));
    cout << "\n>Dao ham cap 1 cua dt2 = ";
    xuatDonThuc(daoHam(dt2));

    float x;
    cout << "\nNhap gia tri x can tinh: ";
    cin >> x;
    cout << "> Gia tri don thuc 1 tai x=" << x << " la: " << tinhGiaTri(dt1, x) << endl;
    cout << "> Gia tri don thuc 2 tai x=" << x << " la: " << tinhGiaTri(dt2, x) << endl;
    return 0;
}