#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

long long power(int a, int b)
{
    int res = 1;
    for (int i = 0; i < b; i++)
    {
        res *= a;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    long long tuSo = power(3, n) - 3 * (power(2, n) - 2);
    long long mauSo = power(3, n);
    long long tmp = gcd(tuSo, mauSo);
    cout << tuSo / tmp << "/" << mauSo / tmp;
}

// 14329489/14348907
// 14329489/14348907