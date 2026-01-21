#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int sum = 0;
    for (int i = 1; i <= m; i++)
    {
        if (m % i == 0 && n % i == 0)
        {
            sum += i;
        }
    }
    cout << sum;
}