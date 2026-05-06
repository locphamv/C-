#include <bits/stdc++.h>
using namespace std;

struct P
{
    long long x, y;
};

bool before(const P &a, const P &b)
{
    if (a.x != b.x)
        return a.x < b.x;
    return a.y > b.y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<P> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }

    for (int w = 1; w < n; w <<= 1)
    {
        for (int l = 0; l < n; l += (w << 1))
        {
            int m = min(l + w, n);
            int r = min(l + (w << 1), n);

            int i = l, j = m, k = l;

            while (i < m && j < r)
            {
                if (before(a[i], a[j]))
                    b[k++] = a[i++];
                else
                    b[k++] = a[j++];
            }

            while (i < m)
                b[k++] = a[i++];
            while (j < r)
                b[k++] = a[j++];
        }
        a.swap(b);
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i].x << ' ' << a[i].y << '\n';
    }

    return 0;
}