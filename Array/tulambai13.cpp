
#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100

void NhapmangSNT(int a[], int &n);
int SoPhanTuChuaY(int a[], int n, int y);

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    if (n % 2 == 0 && n != 2)
    {
        return false;
    }
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void NhapmangSNT(int a[], int &n)
{
    cin >> n;
    int i = 2;
    int k = 0;
    while (k < n)
    {
        if (isPrime(i))
        {
            a[k] = i;
            k++;
        }
        i++;
    }
}

bool chuaSoY(int n, int y)
{
    // if (n == y)
    // {
    //     return true;
    // } khong can thiet vi n%10 chinh bang n neu n la mot chu so
    while (n > 0)
    {
        if (n % 10 == y)
        {
            return true;
        }
        else
        {
            n = n / 10;
        }
    }
    return false;
}

int SoPhanTuChuaY(int a[], int n, int y)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (chuaSoY(a[i], y))
        {
            dem++;
        }
    }
    return dem;
}

int main()
{
    int a[MAX], n, y;
    cin >> y;
    NhapmangSNT(a, n);
    cout << SoPhanTuChuaY(a, n, y) << endl;
    return 0;
}