#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    long long x;
    cin >> x;
    long long tuso = 1;
    long long mauso;
    double kq;
    for (long long i = 1; i <= x; i++)
    {
        mauso = 2 * x + 1;
        kq += (float)tuso / mauso;
    }
    cout << setprecision(6) << kq;

    return 0;
}