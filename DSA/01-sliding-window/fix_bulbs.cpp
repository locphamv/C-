#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k, b;
        cin >> n >> k >> b;
        int a[1000001] = {0};

        for (int i = 0; i < b; i++)
        {
            int x;
            cin >> x;
            a[x] = 1;
        }

        int cnt = 0;
        for (int i = 1; i <= k; i++)
        {
            if (a[i] == 1)
            {
                ++cnt;
            }
        }

        int ans = cnt;
        for (int i = k + 1; i < n; i++)
        {
            cnt = cnt + a[i] - a[i - k];
            ans = min(ans, cnt);
        }

        cout << ans;
    }
}