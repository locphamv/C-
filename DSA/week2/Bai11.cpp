#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<long long> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    while (Q--)
    {
        long long x;
        cin >> x;

        auto it = lower_bound(a.begin(), a.end(), x);

        if (it == a.end())
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << *it << '\n';
        }
    }

    return 0;
}