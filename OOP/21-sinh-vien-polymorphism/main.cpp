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
    vector<SinhVien *> sv;

    cout << "\nNhap sinh vien dai hoc: ";
    SinhVienDaiHoc *dhMax = nullptr;
    for (int i = 0; i < m; i++)
    {
        cout << "\nNhap sinh vien thu " << i + 1 << ": \n";
        SinhVienDaiHoc *dh = new SinhVienDaiHoc;
        dh->nhap();
        sv.push_back(dh);

        if (dhMax == nullptr || dh->getDtb() > dhMax->getDtb())
        {
            dhMax = dh;
        }
    }
    cout << "\nNhap sinh vien cao dang: ";
    SinhVienCaoDang *cdMax = nullptr;
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap sinh vien thu " << i + 1 << ": \n";

        SinhVienCaoDang *cd = new SinhVienCaoDang;
        cd->nhap();
        sv.push_back(cd);

        if (cdMax == nullptr || cd->getDtb() > cdMax->getDtb())
        {
            cdMax = cd;
        }
    }

    cout << "\n---Danh sach cac sinh vien nhap vao---";
    int count = 1;
    for (int i = 0; i < sv.size(); i++)
    {
        cout << "\nSinh vien thu " << count++ << ": \n";
        sv[i]->xuat();
    }

    cout << "\n---Danh sach sinh vien du dieu kien tot nghiep---";
    count = 1;
    for (int i = 0; i < sv.size(); i++)
    {
        if (sv[i]->duDieuKien())
        {
            cout << "\nSinh vien thu " << count++ << ": \n";
            sv[i]->xuat();
        }
    }

    int countDh = 0;
    int countCd = 0;
    cout << "\n---Danh sach sinh vien KHONG du dieu kien tot nghiep---";
    count = 1;
    for (int i = 0; i < sv.size(); i++)
    {

        if (!sv[i]->duDieuKien())
        {
            cout << "\nSinh vien thu " << count++ << ": \n";
            sv[i]->xuat();
            if (dynamic_cast<SinhVienDaiHoc *>(sv[i]) != nullptr)
                countDh++;
            else if (dynamic_cast<SinhVienCaoDang *>(sv[i]) != nullptr)
                countCd++;
        }
    }

    if (dhMax != nullptr)
    {
        cout << "\n---Sinh vien dai hoc co diem trung binh cao nhat---\n";
        dhMax->xuat();
    }
    else
    {
        cout << "\nKhong co sinh vien dai hoc.\n";
    }
    if (cdMax != nullptr)
    {
        cout << "\n---Sinh vien cao dang co diem trung binh cao nhat---\n";
        cdMax->xuat();
    }
    else
    {
        cout << "\nKhong co sinh vien cao dang.\n";
    }

    cout << "\nSo sinh vien dai hoc KHONG du dieu kien tot nghiep: " << countDh << endl;
    cout << "\nSo sinh vien cao dang KHONG du dieu kien tot nghiep: " << countCd << endl;

    for (int i = 0; i < sv.size(); i++)
    {
        delete sv[i];
    }
    sv.clear();
}