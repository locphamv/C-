#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    long long min1 = LLONG_MAX, min2 = LLONG_MAX;
    long long max1 = LLONG_MIN, max2 = LLONG_MIN;

    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;

        if (x <= min1)
        {
            min2 = min1;
            min1 = x;
        }
        else if (x < min2)
        {
            min2 = x;
        }

        if (x >= max1)
        {
            max2 = max1;
            max1 = x;
        }
        else if (x > max2)
        {
            max2 = x;
        }
    }

    long long ans = 0;
    if (n >= 4)
    {
        ans = (max1 - min1) + (max2 - min2);
    }
    else
    {

        ans = (max1 - min1);
    }

    cout << ans << "\n";
}

int main()
{

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}