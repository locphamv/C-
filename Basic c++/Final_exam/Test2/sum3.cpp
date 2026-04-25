#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

float sum(int n)
{
    if (n == 0)
        return 0;
    return sqrt(n + sum(n - 1));
}

int main()
{
    int m;
    cin >> m;
    cout << fixed << setprecision(2) << sum(m);
}