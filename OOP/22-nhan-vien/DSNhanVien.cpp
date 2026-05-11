#include "DSNhanVien.h"
using namespace std;

void DSNhanVien::nhapDS()
{
    int m, n;
    cout << "Nhap so luong lap trinh vien: ";
    cin >> m;
    cout << "Nhap so luong kiem chung vien: ";
    cin >> n;

    for (int i = 0; i < m; i++)
    {
        LapTrinhVien *p = new LapTrinhVien;
        p->nhap();
        dsnv.push_back(p);
    }
    for (int i = 0; i < n; i++)
    {
        KiemChungVien *p = new KiemChungVien;
        p->nhap();
        dsnv.push_back(p);
    }
}

void DSNhanVien::xuatDS()
{
    cout << "\n-----Danh sach nhan vien-----\n";
    for (int i = 0; i < dsnv.size(); i++)
    {
        dsnv[i]->xuat();
        cout << "\n";
    }
}

void DSNhanVien::xuatBeHonTB()
{
    double sum = 0;
    for (int i = 0; i < dsnv.size(); i++)
    {
        sum += dsnv[i]->tinhLuong();
    }
    cout << "\nDanh sach nhan vien luong duoi tb---\n";
    for (int i = 0; i < dsnv.size(); i++)
    {
        if (dsnv[i]->tinhLuong() < sum / dsnv.size())
        {
            dsnv[i]->xuat();
            cout << "\n";
        }
    }
}

void DSNhanVien::xuatLuongMax()
{
    NhanVien *p = nullptr;
    for (int i = 0; i < dsnv.size(); i++)
    {
        if (i == 0 || dsnv[i]->tinhLuong() > p->tinhLuong())
        {
            p = dsnv[i];
        }
    }
    cout << "\n---Nhan vien co luong cao nhat---\n";
    p->xuat();
}

void DSNhanVien::xuatLuongMin()
{
    NhanVien *p = nullptr;
    for (int i = 0; i < dsnv.size(); i++)
    {
        if (i == 0 || dsnv[i]->tinhLuong() < p->tinhLuong())
        {
            p = dsnv[i];
        }
    }
    cout << "\n---Nhan vien co luong thap nhat---\n";
    p->xuat();
}

void DSNhanVien::xuatLapTrinhVienMax()
{
    LapTrinhVien *p = nullptr;
    for (int i = 0; i < dsnv.size(); i++)
    {
        LapTrinhVien *q = dynamic_cast<LapTrinhVien *>(dsnv[i]);
        if (q)
        {
            if (p == nullptr || q->tinhLuong() > p->tinhLuong())
            {
                p = q;
            }
        }
    }
    cout << "\n---Lap trinh vien co luong cao nhat---\n";
    p->xuat();
}

void DSNhanVien::xuatKiemChuongVienMin()
{
    KiemChungVien *p = nullptr;
    for (int i = 0; i < dsnv.size(); i++)
    {
        KiemChungVien *q = dynamic_cast<KiemChungVien *>(dsnv[i]);
        if (q)
        {
            if (p == nullptr || q->tinhLuong() < p->tinhLuong())
            {
                p = q;
            }
        }
    }
    cout << "\n---Kiem chung vien co luong thap nhat---\n";
    p->xuat();
}

DSNhanVien::~DSNhanVien()
{
    for (int i = 0; i < dsnv.size(); i++)
    {
        delete dsnv[i];
    }
    dsnv.clear();
}