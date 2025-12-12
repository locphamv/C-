#include <iostream>
#include <iomanip>
using namespace std;

struct Tinh
{
    int maTinh;
    char tenTinh[100];
    long danSo;
    float dienTich;
};

void nhapTinh(Tinh &t)
{
    cout << "Nhap Ma tinh: ";
    cin >> t.maTinh;
    char rac;
    cin.get(rac);

    cout << "Nhap Ten tinh: ";

    cin.getline(t.tenTinh, 100);

    cout << "Nhap Dan so: ";
    cin >> t.danSo;

    cout << "Nhap Dien tich: ";
    cin >> t.dienTich;
}

void xuatTinh(Tinh t)
{
    cout << "Ma: " << t.maTinh
         << " | Ten: " << t.tenTinh
         << " | Dan so: " << t.danSo
         << " | Dien tich: " << t.dienTich << endl;
}

void nhapDanhSach(Tinh ds[], int &n)
{
    cout << "Nhap so luong tinh: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap tinh thu " << i + 1 << " : \n";
        nhapTinh(ds[i]);
    }
}

void xuatDanhSach(Tinh ds[], int n)
{
    cout << "\nDANH SACH TINH: \n";
    for (int i = 0; i < n; i++)
    {
        xuatTinh(ds[i]);
    }
}

void xuatTinhDanSoLon(Tinh ds[], int n)
{
    cout << "\nCAC TINH DAN SO > 1 TRIEU: \n";
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds[i].danSo > 1000000)
        {
            xuatTinh(ds[i]);
            dem++;
        }
    }
    if (dem == 0)
        cout << "Khong co tinh nao.\n";
}

void timMaxDienTich(Tinh ds[], int n)
{
    cout << "\nTINH CO DIEN TICH LON NHAT: \n";
    if (n == 0)
        return;

    int viTriMax = 0;

    for (int i = 1; i < n; i++)
    {
        if (ds[i].dienTich > ds[viTriMax].dienTich)
        {
            viTriMax = i;
        }
    }
    xuatTinh(ds[viTriMax]);
}

int main()
{

    Tinh dsTinh[100];
    int n;

    nhapDanhSach(dsTinh, n);
    xuatDanhSach(dsTinh, n);
    xuatTinhDanSoLon(dsTinh, n);
    timMaxDienTich(dsTinh, n);

    return 0;
}