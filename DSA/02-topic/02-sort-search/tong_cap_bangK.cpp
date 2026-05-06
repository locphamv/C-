//lower_bound and upper_bound from i+1 to n to search for k-a[i]
//count+= upper-lower

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    long long count = 0;
    for (int i = 0; i < n; i++)
    {
        auto it1 = lower_bound(a.begin() + i + 1, a.begin() + n, k - a[i]);
        auto it2 = upper_bound(a.begin() + i + 1, a.begin() + n, k - a[i]);
        count += (it2 - it1);
    }
    cout << count;
}