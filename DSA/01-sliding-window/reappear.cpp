#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    set<int> s;
    for (int i = 0; i < k; i++)
    {
        if (s.count(a[i]))
        {
            return true;
        }
        s.insert(a[i]);
    }

    for (int i = k; i < n; i++)
    {
        s.erase(a[i - k]);
        if (s.count(a[i]))
        {
            return true;
        }
        s.insert(a[i]);
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        if (check())
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
    return 0;
}