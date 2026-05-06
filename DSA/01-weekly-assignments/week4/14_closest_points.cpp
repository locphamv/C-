#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, x, y;
    cin >> n >> k;
    typedef pair<long long, pair<int, int>> Point;
    priority_queue<Point, vector<Point>, greater<Point>> minHeap;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        long long tmp = 1LL * x * x + 1LL * y * y;
        minHeap.push({tmp, {x, y}});
    }

    for (int i = 0; i < k; i++)
    {
        cout << minHeap.top().second.first << " " << minHeap.top().second.second;
        cout << "\n";
        minHeap.pop();
    }
}
