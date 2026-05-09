#include "NhanVien.h"
#include "NhanVienSanXuat.h"
#include "NhanVienVanPhong.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

bool ngaySinhNhoHon(const string &a, const string &b)
{
    int ngay1 = stoi(a.substr(0, 2));
    int thang1 = stoi(a.substr(3, 2));
    int nam1 = stoi(a.substr(6, 4));

    int ngay2 = stoi(b.substr(0, 2));
    int thang2 = stoi(b.substr(3, 2));
    int nam2 = stoi(b.substr(6, 4));

    if (nam1 != nam2)
        return nam1 < nam2;
    if (thang1 != thang2)
        return thang1 < thang2;
    return ngay1 < ngay2;
}

int main()
{
    cout<<fixed<<setprecision(0);
    int m, n;
    cout << "Nhap so nhan vien san xuat: ";
    cin >> m;

    cout << "Nhap so nhan vien van phong: ";
    cin >> n;

    vector<NhanVien *> ds;

    // Nhap nhan vien san xuat
    for (int i = 0; i < m; i++)
    {
        cout << "\nNhap nhan vien san xuat thu " << i + 1 << ":\n";
        NhanVien *p = new NhanVienSanXuat;
        p->nhap();
        ds.push_back(p);
    }

    // Nhap nhan vien van phong
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap nhan vien van phong thu " << i + 1 << ":\n";
        NhanVien *p = new NhanVienVanPhong;
        p->nhap();
        ds.push_back(p);
    }

    cout << "\n========= DANH SACH NHAN VIEN =========\n";

    double tongLuong = 0;
    NhanVienSanXuat *nvSanXuatLuongThapNhat = nullptr;
    NhanVienVanPhong *nvVanPhongLonTuoiNhat = nullptr;

    for (int i = 0; i < ds.size(); i++)
    {
        ds[i]->xuat();
        cout << "Luong: " << ds[i]->tinhLuong() << endl;
        cout << "-----------------------------\n";

        tongLuong += ds[i]->tinhLuong();

        // Tim nhan vien san xuat co luong thap nhat
        NhanVienSanXuat *sx = dynamic_cast<NhanVienSanXuat *>(ds[i]);
        if (sx != nullptr)
        {
            if (nvSanXuatLuongThapNhat == nullptr ||
                sx->tinhLuong() < nvSanXuatLuongThapNhat->tinhLuong())
            {
                nvSanXuatLuongThapNhat = sx;
            }
        }

        // Tim nhan vien van phong lon tuoi nhat
        NhanVienVanPhong *vp = dynamic_cast<NhanVienVanPhong *>(ds[i]);
        if (vp != nullptr)
        {
            if (nvVanPhongLonTuoiNhat == nullptr ||
                ngaySinhNhoHon(vp->getNgaySinh(), nvVanPhongLonTuoiNhat->getNgaySinh()))
            {
                nvVanPhongLonTuoiNhat = vp;
            }
        }
    }

    cout << "\nTong luong cong ty phai tra: " << tongLuong << endl;

    if (nvSanXuatLuongThapNhat != nullptr)
    {
        cout << "\nNHAN VIEN SAN XUAT CO LUONG THAP NHAT:\n";
        nvSanXuatLuongThapNhat->xuat();
        cout << "Luong: " << nvSanXuatLuongThapNhat->tinhLuong() << endl;
    }
    else
    {
        cout << "\nKhong co nhan vien san xuat.\n";
    }

    if (nvVanPhongLonTuoiNhat != nullptr)
    {
        cout << "\nNHAN VIEN VAN PHONG LON TUOI NHAT:\n";
        nvVanPhongLonTuoiNhat->xuat();
        cout << "Luong: " << nvVanPhongLonTuoiNhat->tinhLuong() << endl;
    }
    else
    {
        cout << "\nKhong co nhan vien van phong.\n";
    }

    for (int i = 0; i < ds.size(); i++)
    {
        delete ds[i];
    }

    return 0;
}