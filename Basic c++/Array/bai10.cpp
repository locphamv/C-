#include <iostream>
using namespace std;
bool isprime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    if (n != 2 && n % 2 == 0)
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
void nhapMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void xuatMang(int a[], int &n)
{
    bool hasIsprime = false;
    for (int i = 0; i < n; i++)
    {
        if (isprime(a[i]))
        {
            cout << a[i] << " ";
            hasIsprime = true;
        }
    }

    if (hasIsprime == false)
    {
        cout << "0";
    }
}

int main()
{
    int n;
    int a[10005];
    cin >> n;
    nhapMang(a, n);
    xuatMang(a, n);
    return 0;
}