#include <bits/stdc++.h>
using namespace std;

long long soNgayCan(long long a, long long k, long long b, long long m, long long n)
{
    long long left = 0;
    long long right = (n / (a + b) + 5) * 2;
    long long dem = -1;
    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        long long ans = (mid - mid / k) * a + (mid - mid / m) * b;
        if (ans >= n)
        {
            dem = mid;
            right = mid - 1;
        }
        else if (ans < n)
        {
            left = mid + 1;
        }
    }

    return dem;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, k, b, m, n;
    cin >> a >> k >> b >> m >> n;

    cout << soNgayCan(a, k, b, m, n);
}