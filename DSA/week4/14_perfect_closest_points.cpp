#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, pair<int, int>> Point;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, x, y;
    cin >> n >> k;

    priority_queue<Point> maxHeap;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        long long tmp = 1LL * x * x + 1LL * y * y;
        maxHeap.push({tmp, {x, y}});
        if (maxHeap.size() > k)
        {
            maxHeap.pop();
        }
    }

    while (!maxHeap.empty())
    {
        cout << maxHeap.top().second.first << " " << maxHeap.top().second.second;
        cout << "\n";
        maxHeap.pop();
    }
}