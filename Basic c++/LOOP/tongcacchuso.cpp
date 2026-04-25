#include <iostream>
using namespace std;
int soChuSo(int n)
{
    int dem = 0;
    while (n > 0)
    {
        n = n / 10;
        dem++;
    }
    return dem;
}
int tongChuSo(int n, int dem)
{
    int *a = new int[dem];
    int i = 0;
    while (n > 0)
    {
        a[i] = n % 10;
        i++;
        n = n / 10;
    }

    int kq = 0;
    for (int i = 0; i < dem; i++)
    {
        kq = kq + a[i];
    }
    delete[] a;
    return kq;
}

int main()
{
    int n;
    cin >> n;
    cout << tongChuSo(n, soChuSo(n));
    return 0;
}