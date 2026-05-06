#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T,n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long sum = 0;
    long long min=-99999999999;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];

        if (i >= k)
        {
            sum -= a[i - k];
        }

        if (i >= k - 1)
        {
            cout << sum << " ";
        }
    }
}