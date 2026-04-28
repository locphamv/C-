#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(const vector<ll> &a, int n, ll h, ll k)
{
    ll hours = 0;
    for (int i = 0; i < n; i++)
    {
        hours += (a[i] + k - 1) / k;
        if (hours > h)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll h;
    cin >> n >> h;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll left = 1, right = *max_element(a.begin(), a.end());
    ll ans = right;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        if (check(a, n, h, mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << ans;
}