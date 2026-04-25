#include <iomanip>
#include <iostream>
#include <stdio.h>
using namespace std;
#define MAXN 100

struct SinhVien
{
    char MASV[10];
    char HoTen[100];
    char NgaySinh[12];
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};

void Nhap(SinhVien a[], int &n)
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        cin.getline(a[i].MASV, 10);
        cin.getline(a[i].HoTen, 100);
        cin.getline(a[i].NgaySinh, 12);
        cin >> a[i].GioiTinh >> a[i].DiemToan >> a[i].DiemLy >> a[i].DiemHoa;
        a[i].DTB = (a[i].DiemToan + a[i].DiemLy + a[i].DiemHoa) / 3;
    }
}
void Xuat(SinhVien a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i].MASV << " " << a[i].HoTen << " " << a[i].NgaySinh << " " << a[i].GioiTinh << " " << a[i].DiemToan << " " << a[i].DiemLy << " " << a[i].DiemHoa << " " << setprecision(3) << a[i].DTB << endl;
    }
}

int main()
{
    SinhVien A[MAXN];
    int n;
    Nhap(A, n);
    Xuat(A, n);
    return 0;
}
