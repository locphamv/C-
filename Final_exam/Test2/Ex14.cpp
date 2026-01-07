#include <iostream>
#include <string.h>
using namespace std;

struct MONDANGKY
{
    string MaMon;
    bool ThucHanh;
    int SoTin;
    int NgayHoc;
};

struct DANGKY
{
    int MASV;
    int SoMon;
    MONDANGKY ds1[100];
    float GPA;
};

void nhap1MON(MONDANGKY a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].MaMon >> a[i].ThucHanh >> a[i].SoTin >> a[i].NgayHoc;
    }
}

void nhapSV(DANGKY ds[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> ds[i].MASV >> ds[i].SoMon >> ds[i].GPA;
        nhap1MON(ds[i].ds1, ds[i].SoMon);
    }
}

bool checkGPAvaSoTin(DANGKY &ds)
{
    bool check = true;
    int tongTinChi = 0;
    for (int i = 0; i < ds.SoMon; i++)
    {
        tongTinChi += ds.ds1[i].SoTin;
    }
    if (ds.GPA < 8 && tongTinChi > 24)
    {
        check = false;
    }
    else if (ds.GPA >= 8 && tongTinChi > 30)
    {
        check = false;
    }
    return check;
}

bool checkMasv(DANGKY &ds)
{
    bool check = true;
    if (ds.MASV < 100000 || ds.MASV > 999999)
    {
        check = false;
    }
    return check;
}
bool checkMonHoc(DANGKY &ds)
{
    for (int i = 0; i < ds.SoMon; i++)
    {
        for (int j = 0; j < ds.SoMon; j++)
        {
            MONDANGKY &a = ds.ds1[i];
            MONDANGKY &b = ds.ds1[j];
            if (a.MaMon == b.MaMon && a.ThucHanh != b.ThucHanh)
            {
                if (a.NgayHoc != b.NgayHoc)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    DANGKY *ds = new DANGKY[n];
    nhapSV(ds, n);
    bool kiemTra = true;
    for (int i = 0; i < n; i++)
    {
        if (!checkGPAvaSoTin(ds[i]))
        {
            cout << ds[i].MASV << " " << "SoTin" << endl;
            kiemTra = false;
        }
        if (!checkMasv(ds[i]))
        {
            cout << ds[i].MASV << " " << "MASV" << endl;
            kiemTra = false;
        }
        if (!checkMonHoc(ds[i]))
        {
            cout << ds[i].MASV << " " << "NgayHoc";
            kiemTra = false;
        }
    }
    if (kiemTra)
    {
        cout << "Not found";
    }
    return 0;
}