#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> minHeap;

    int k;
    cin >> k;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        minHeap.push(x);
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }
        if (i < k)
        {
            cout << -1 << "\n";
        }
        else
        {

            cout << minHeap.top() << "\n";
        }
    }
}