#include <iostream>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b)
{
    long long r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    double a;
    long long n;

    cin >> a >> n;
    long long total = round(a * n);
    long long integer_part = total / n;
    long long numerator = total % n;

    if (numerator == 0)
    {

        cout << integer_part;
    }
    else
    {

        long long common = gcd(numerator, n);

        numerator = numerator / common;
        long long denominator = n / common;

        if (integer_part != 0)
        {
            cout << integer_part << " " << numerator << "/" << denominator;
        }
        else
        {

            cout << numerator << "/" << denominator;
        }
    }
    return 0;
}