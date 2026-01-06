#include <iostream>
using namespace std;

void nhapMang(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

bool kiemTra(int b)
{
    if (b < 2)
        return false;
    if (b % 2 == 0 && b != 2)
        return false;
    for (int i = 3; i * i <= b; i += 2)
    {
        if (b % i == 0)
            return false;
    }
    return true;
}

int tinhTongSNT(int a[], int n)
{

    int s = 0;
    for (int i = 0; i < n; i++)
    {
        if (kiemTra(a[i]))
        {
            s += a[i];
        }
    }
    return s;
}

int giaTriLonThuK(int a[], int n, int k)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }

    return a[n - k];
}

int main()
{
    int a[50], n = 0;
    int S, k, maxval;
    nhapMang(a, n);
    S = tinhTongSNT(a, n);
    do
    {
        cout << "Nhap gia tri k=";
        cin >> k;
    } while (k < 1 || k > n);
    maxval = giaTriLonThuK(a, n, k);
    cout << "Gia tri lon thu " << k << " la: " << maxval;
}