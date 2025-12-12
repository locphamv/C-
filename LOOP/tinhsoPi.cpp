#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    float sum = 0;
    for (int i = 0; i <= n; i++)
    {
        float sign = 1.0 / (float)(2.0 * i + 1.0);
        if (i % 2 != 0)
        {
            sign = -sign;
        }
        sum += sign;
    }
    cout << 4 * sum;
    return 0;
}