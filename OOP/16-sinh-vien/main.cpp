#include "SinhVienCaoDang.h"
#include "SinhVienDaiHoc.h"
#include <vector>
using namespace std;

int main()
{
    int m, n;
    cout << "Nhap so sinh vien dai hoc: ";
    cin >> m;
    cout << "Nhap so sinh vien cao dang: ";
    cin >> n;
    vector<SinhVienDaiHoc> dh(m);
    vector<SinhVienCaoDang> cd(n);

    cout << "\nNhap sinh vien dai hoc: ";
    double maxDtb;
    for (int i = 0; i < m; i++)
    {
        cout << "\nNhap sinh vien thu " << i + 1 << ": \n";
        dh[i].nhap();
        if (i == 0 || dh[i].getDtb() > maxDtb)
        {
            maxDtb = dh[i].getDtb();
        }
    }
    cout << "\nNhap sinh vien cao dang: ";
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap sinh vien thu " << i + 1 << ": \n";
        cd[i].nhap();
    }

    cout << "\n---Danh sach cac sinh vien nhap vao---";
    int count = 1;
    for (int i = 0; i < m; i++)
    {
        cout << "\nSinh vien thu " << count++ << ": \n";

        dh[i].xuat();
    }
    for (int i = 0; i < n; i++)
    {
        cout << "\nSinh vien thu " << count++ << ": \n";

        cd[i].xuat();
    }

    cout << "\n---Danh sach sinh vien du dieu kien tot nghiep---";
    count = 1;
    for (int i = 0; i < m; i++)
    {
        cout << "\nSinh vien thu " << count++ << ": \n";
        if (dh[i].duDieuKien())
        {
            dh[i].xuat();
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << "\nSinh vien thu " << count++ << ": \n";
        if (cd[i].duDieuKien())
        {
            cd[i].xuat();
        }
    }

    cout << "\n---Danh sach sinh vien KHONG du dieu kien tot nghiep---";
    count = 0;
    for (int i = 0; i < m; i++)
    {
        cout << "\nSinh vien thu " << count++ << ": \n";
        if (!dh[i].duDieuKien())
        {
            dh[i].xuat();
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << "\nSinh vien thu " << count++ << ": \n";
        if (!cd[i].duDieuKien())
        {
            cd[i].xuat();
        }
    }

    cout << "\n---Sinh vien dai hoc co diem trung binh cao nhat---\n";
}