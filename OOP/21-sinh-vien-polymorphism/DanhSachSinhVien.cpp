#include "DanhSachSinhVien.h"
#include <iostream>
using namespace std;

DanhSachSinhVien::~DanhSachSinhVien()
{
    for (int i = 0; i < sv.size(); i++)
    {
        delete sv[i];
    }
    sv.clear();
}

void DanhSachSinhVien::nhap()
{
    int m, n;
    cout << "Nhap so sinh vien dai hoc: ";
    cin >> m;
    cout << "Nhap so sinh vien cao dang: ";
    cin >> n;

    cout << "\nNhap sinh vien dai hoc: ";
    for (int i = 0; i < m; i++)
    {
        cout << "\nNhap sinh vien thu " << i + 1 << ": \n";
        SinhVienDaiHoc* dh = new SinhVienDaiHoc;
        dh->nhap();
        sv.push_back(dh);
    }

    cout << "\nNhap sinh vien cao dang: ";
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap sinh vien thu " << i + 1 << ": \n";
        SinhVienCaoDang* cd = new SinhVienCaoDang;
        cd->nhap();
        sv.push_back(cd);
    }
}

void DanhSachSinhVien::xuatDanhSach() const
{
    cout << "\n---Danh sach cac sinh vien nhap vao---";
    int count = 1;
    for (int i = 0; i < sv.size(); i++)
    {
        cout << "\nSinh vien thu " << count++ << ": \n";
        sv[i]->xuat();
    }
}

void DanhSachSinhVien::xuatDuDieuKien() const
{
    cout << "\n---Danh sach sinh vien du dieu kien tot nghiep---";
    int count = 1;
    for (int i = 0; i < sv.size(); i++)
    {
        if (sv[i]->duDieuKien())
        {
            cout << "\nSinh vien thu " << count++ << ": \n";
            sv[i]->xuat();
        }
    }
}

void DanhSachSinhVien::xuatKhongDuDieuKien() const
{
    cout << "\n---Danh sach sinh vien KHONG du dieu kien tot nghiep---";
    int count = 1;
    for (int i = 0; i < sv.size(); i++)
    {
        if (!sv[i]->duDieuKien())
        {
            cout << "\nSinh vien thu " << count++ << ": \n";
            sv[i]->xuat();
        }
    }
}

void DanhSachSinhVien::xuatDaiHocDtbCaoNhat() const
{
    SinhVienDaiHoc* p = nullptr;

    for (int i = 0; i < sv.size(); i++)
    {
        SinhVienDaiHoc* dh = dynamic_cast<SinhVienDaiHoc*>(sv[i]);
        if (dh != nullptr)
        {
            if (p == nullptr || dh->getDtb() > p->getDtb())
            {
                p = dh;
            }
        }
    }

    if (p != nullptr)
    {
        cout << "\n---Sinh vien dai hoc co diem trung binh cao nhat---\n";
        p->xuat();
    }
    else
    {
        cout << "\nKhong co sinh vien dai hoc.\n";
    }
}

void DanhSachSinhVien::xuatCaoDangDtbCaoNhat() const
{
    SinhVienCaoDang* p = nullptr;

    for (int i = 0; i < sv.size(); i++)
    {
        SinhVienCaoDang* cd = dynamic_cast<SinhVienCaoDang*>(sv[i]);
        if (cd != nullptr)
        {
            if (p == nullptr || cd->getDtb() > p->getDtb())
            {
                p = cd;
            }
        }
    }

    if (p != nullptr)
    {
        cout << "\n---Sinh vien cao dang co diem trung binh cao nhat---\n";
        p->xuat();
    }
    else
    {
        cout << "\nKhong co sinh vien cao dang.\n";
    }
}

void DanhSachSinhVien::xuatSoLuongKhongDuDieuKien() const
{
    int countDh = 0;
    int countCd = 0;

    for (int i = 0; i < sv.size(); i++)
    {
        if (!sv[i]->duDieuKien())
        {
            if (dynamic_cast<SinhVienDaiHoc*>(sv[i]) != nullptr)
                countDh++;
            else if (dynamic_cast<SinhVienCaoDang*>(sv[i]) != nullptr)
                countCd++;
        }
    }

    cout << "\nSo sinh vien dai hoc KHONG du dieu kien tot nghiep: " << countDh << endl;
    cout << "So sinh vien cao dang KHONG du dieu kien tot nghiep: " << countCd << endl;
}