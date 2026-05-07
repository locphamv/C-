#include "NhanVienSanXuat.h"
#include "NhanVienVanPhong.h"
#include <iomanip>
#include <vector>
using namespace std;
int main()
{
    cout << fixed << setprecision(0);
    int m, n;
    cout << "Nhap so nhan vien san xuat: ";
    cin >> m;
    cout << "Nhap so nhan vien van phong: ";
    cin >> n;

    vector<NhanVienSanXuat> sx(m);
    vector<NhanVienVanPhong> vp(n);

    cout << "\n----NHAP THONG TIN NHAN VIEN----";
    cout << "\nNhap nhan vien san suat: ";
    for (int i = 0; i < m; i++)
    {
        cout << "\nNhan vien " << i + 1 << ": \n";
        sx[i].nhap();
    }

    cout << "\nNhap nhan vien van phong: ";
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhan vien " << i + 1 << ": \n";
        vp[i].nhap();
    }

    double sum = 0;
    cout << "\n----XUAT DANH SACH NHAN VIEN----";
    cout << "\nNhan vien san suat gom: ";
    for (int i = 0; i < m; i++)
    {
        cout << "\nNhan vien " << i + 1 << ": \n";
        sx[i].xuat();
        sum += sx[i].tinhLuong();
    }
    cout << "\nNhan vien van phong gom: ";
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhan vien " << i + 1 << ": \n";
        vp[i].xuat();
        sum += vp[i].tinhLuong();
    }

    cout << "\nTONG LUONG MA CONG TY PHAI TRA CHO NHAN VIEN:\n" << sum;
}