#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(const vector<ll> &a, ll L, ll h)
{
    int n = a.size();
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (h < a[i])
        {
            sum += a[i] - h;
        }
        if (sum >= L)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, L;
    cin >> n >> L;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll left = 0;
    ll right = *max_element(a.begin(), a.end());
    ll ans = -1;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        // cout << left << " " << mid << " " << right << endl;

        if (check(a, L, mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << ans;
}