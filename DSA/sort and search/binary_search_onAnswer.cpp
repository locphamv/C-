#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll produced(const vector<int> &a, ll x, ll t)
{
    ll res = 0;
    for (int v : a)
    {
        res += x / v;
        if (res >= t)
            return res; // tránh tính thừa, cũng giảm nguy cơ overflow
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll t;
    cin >> n >> t;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll left = 0;
    ll right = 1e18;

    while (left < right)
    {
        ll mid = left + (right - left) / 2;

        if (produced(a, mid, t) >= t)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << left;
}