#include "DanhSachNhanVien.h"
#include <iostream>
using namespace std;

bool DanhSachNhanVien::ngaySinhNhoHon(const string& a, const string& b) const
{
    int ngay1 = stoi(a.substr(0, 2));
    int thang1 = stoi(a.substr(3, 2));
    int nam1 = stoi(a.substr(6, 4));

    int ngay2 = stoi(b.substr(0, 2));
    int thang2 = stoi(b.substr(3, 2));
    int nam2 = stoi(b.substr(6, 4));

    if (nam1 != nam2) return nam1 < nam2;
    if (thang1 != thang2) return thang1 < thang2;
    return ngay1 < ngay2;
}

DanhSachNhanVien::~DanhSachNhanVien()
{
    for (int i = 0; i < ds.size(); i++)
    {
        delete ds[i];
    }
    ds.clear();
}

void DanhSachNhanVien::nhap()
{
    int m, n;
    cout << "Nhap so nhan vien san xuat: ";
    cin >> m;

    cout << "Nhap so nhan vien van phong: ";
    cin >> n;

    for (int i = 0; i < m; i++)
    {
        cout << "\nNhap nhan vien san xuat thu " << i + 1 << ":\n";
        NhanVien* p = new NhanVienSanXuat;
        p->nhap();
        ds.push_back(p);
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap nhan vien van phong thu " << i + 1 << ":\n";
        NhanVien* p = new NhanVienVanPhong;
        p->nhap();
        ds.push_back(p);
    }
}

void DanhSachNhanVien::xuat() const
{
    cout << "\n========= DANH SACH NHAN VIEN =========\n";
    for (int i = 0; i < ds.size(); i++)
    {
        ds[i]->xuat();
        cout << "Luong: " << ds[i]->tinhLuong() << endl;
        cout << "-----------------------------\n";
    }
}

double DanhSachNhanVien::tongLuong() const
{
    double tong = 0;
    for (int i = 0; i < ds.size(); i++)
    {
        tong += ds[i]->tinhLuong();
    }
    return tong;
}

void DanhSachNhanVien::xuatNhanVienSanXuatLuongThapNhat() const
{
    NhanVienSanXuat* p = nullptr;

    for (int i = 0; i < ds.size(); i++)
    {
        NhanVienSanXuat* sx = dynamic_cast<NhanVienSanXuat*>(ds[i]);
        if (sx != nullptr)
        {
            if (p == nullptr || sx->tinhLuong() < p->tinhLuong())
            {
                p = sx;
            }
        }
    }

    if (p != nullptr)
    {
        cout << "\nNHAN VIEN SAN XUAT CO LUONG THAP NHAT:\n";
        p->xuat();
        cout << "Luong: " << p->tinhLuong() << endl;
    }
    else
    {
        cout << "\nKhong co nhan vien san xuat.\n";
    }
}

void DanhSachNhanVien::xuatNhanVienVanPhongLonTuoiNhat() const
{
    NhanVienVanPhong* p = nullptr;

    for (int i = 0; i < ds.size(); i++)
    {
        NhanVienVanPhong* vp = dynamic_cast<NhanVienVanPhong*>(ds[i]);
        if (vp != nullptr)
        {
            if (p == nullptr || ngaySinhNhoHon(vp->getNgaySinh(), p->getNgaySinh()))
            {
                p = vp;
            }
        }
    }

    if (p != nullptr)
    {
        cout << "\nNHAN VIEN VAN PHONG LON TUOI NHAT:\n";
        p->xuat();
        cout << "Luong: " << p->tinhLuong() << endl;
    }
    else
    {
        cout << "\nKhong co nhan vien van phong.\n";
    }
}