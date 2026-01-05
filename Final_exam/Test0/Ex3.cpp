#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    double result = 0;
    int tuso = 1;
    int mauso = 0;
    for (int i = 1; i < n + 1; i++)
    {
        mauso += i;
        result += (double)tuso / mauso;
    }
    cout << setprecision(10) << result;
    return 0;
}