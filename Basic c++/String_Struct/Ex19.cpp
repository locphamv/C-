
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>
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

void Nhap(char a[])
{
    cin.getline(a, 100);
}
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

void XoaTheoHoTen(SinhVien a[], int &n, char tenxoa[])
{
    int k;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(a[i].HoTen, tenxoa) == 0)
        {
            for (int j = i; j < n - 1; j++)
            {
                a[j] = a[j + 1];
            }
            n--;
            i--;
        }
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
    char hoTenCanXoa[100];
    int n;

    Nhap(hoTenCanXoa);

    Nhap(A, n);

    XoaTheoHoTen(A, n, hoTenCanXoa);

    Xuat(A, n);
    return 0;
}
