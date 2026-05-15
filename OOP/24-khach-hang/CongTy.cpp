#include "CongTy.h"
#include <fstream>
#include <iomanip>
using namespace std;

CongTy::CongTy() : x(0), y(0), z(0)
{
}

CongTy::~CongTy()
{
    for (int i = 0; i < ds.size(); i++)
    {
        delete ds[i];
    }
    ds.clear();
}

bool CongTy::docFile(const string& tenFile)
{
    ifstream fin(tenFile);
    if (!fin.is_open())
    {
        return false;
    }

    fin >> x >> y >> z;

    for (int i = 0; i < x; i++)
    {
        KhachHang* p = new KhachHangA;
        p->nhap(fin);
        ds.push_back(p);
    }

    for (int i = 0; i < y; i++)
    {
        KhachHang* p = new KhachHangB;
        p->nhap(fin);
        ds.push_back(p);
    }

    for (int i = 0; i < z; i++)
    {
        KhachHang* p = new KhachHangC;
        p->nhap(fin);
        ds.push_back(p);
    }

    fin.close();
    return true;
}

double CongTy::tongSoTien() const
{
    double tong = 0;
    for (int i = 0; i < ds.size(); i++)
    {
        tong += ds[i]->tinhTien();
    }
    return tong;
}

bool CongTy::ghiFile(const string& tenFile) const
{
    ofstream fout(tenFile);
    if (!fout.is_open())
    {
        return false;
    }

    fout << x << ' ' << y << ' ' << z << '\n';

    for (int i = 0; i < ds.size(); i++)
    {
        ds[i]->xuat(fout);
    }

    fout << fixed << setprecision(2) << tongSoTien() << '\n';

    fout.close();
    return true;
}