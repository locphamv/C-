
#include <iostream>
using namespace std;

void NhapMang(int *, int);
void XuatMang(int *, int);
void XoaPhanTu(int *, int &, int);

int main()
{
    int n;
    cin >> n;
    int A[10005];
    NhapMang(A, n);

    int x;
    cin >> x;
    XoaPhanTu(A, n, x);

    XuatMang(A, n);
    return 0;
}

void NhapMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void XuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
void XoaPhanTu(int a[], int &n, int x)
{

    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != x)
        {
            a[dem] = a[i];
            dem++;
        }
    }
    n = dem;
}