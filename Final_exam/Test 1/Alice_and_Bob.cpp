#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, k, p, q;

    cin >> n >> k >> p >> q;

    int a = (p - 1) * 2 + q;
    int b1 = a - k;
    int b2 = a + k;
    int best = -1;
    if (1 <= b1 && b1 <= n)
    {
        best = b1;
    }
    if (1 <= b2 && b2 <= n)
    {
        if (best == -1)
        {
            best = b2;
        }
        else
        {
            int rBest = (best + 1) / 2;
            int r2 = (b2 + 1) / 2;
            int dBest = abs(rBest - p);
            int d2 = abs(r2 - p);
            if (d2 < dBest)
                best = b2;
        }
    }
    if (best == -1)
    {
        cout << -1;
    }
    else
    {
        cout << (best + 1) / 2 << " " << ((best % 2 == 1) ? 1 : 2);
    }
    return 0;
}
