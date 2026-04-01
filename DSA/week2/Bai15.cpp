#include <bits/stdc++.h>
using namespace std;

struct Point
{
    long long x, y, z;
};

bool beforePoint(const Point &a, const Point &b)
{
    if (a.x != b.x)
        return a.x < b.x;
    if (a.y != b.y)
        return a.y > b.y;
    return a.z < b.z;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> a(n), temp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }

    for (int width = 1; width < n; width <<= 1)
    {
        for (int left = 0; left < n; left += (width << 1))
        {
            int mid = min(left + width, n);
            int right = min(left + (width << 1), n);

            int i = left, j = mid, k = left;

            while (i < mid && j < right)
            {
                if (beforePoint(a[i], a[j]))
                    temp[k++] = a[i++];
                else
                    temp[k++] = a[j++];
            }

            while (i < mid)
                temp[k++] = a[i++];
            while (j < right)
                temp[k++] = a[j++];
        }
        a.swap(temp);
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i].x << ' ' << a[i].y << ' ' << a[i].z << '\n';
    }

    return 0;
}