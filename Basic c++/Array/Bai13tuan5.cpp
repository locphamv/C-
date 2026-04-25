#include <iostream>
using namespace std;

bool songuyento(int n)
{

    if (n < 2)
        return false;
    if (n == 2)
        return true;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void taorasonguyento(int a[], int n)
{

    int dem = 0;
    int i = 2;
    while (dem < n)
    {
        if (songuyento(i))
        {
            a[dem] = i;
            dem++;
        }
        i++;
    }
}

bool kiemTra(int m, int b)
{
    if (m == 0 && b == 0)
    {
        return true;
    }

    while (m > 0)
    {
        int soduoi;
        soduoi = m % 10;
        if (soduoi == b)
            return true;
        m = m / 10;
    }
    return false;
}

int main()
{
    int y;
    cin >> y;
    int n;
    cin >> n;
    int a[100];
    taorasonguyento(a, n);
    int dem = 0;

    for (int i = 0; i < n; i++)
    {
        bool kiem = kiemTra(a[i], y);
        if (kiem)
        {
            dem++;
        }
    }

    cout << dem;
    return 0;
}
