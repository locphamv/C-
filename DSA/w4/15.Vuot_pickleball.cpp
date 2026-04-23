#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct WindowMedian
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    unordered_map<int, int> toRemove;
    int sizeLo = 0;
    int sizeHi = 0;

    void cleanHeaps()
    {
        while (!maxHeap.empty() && toRemove[maxHeap.top()] > 0)
        {
            toRemove[maxHeap.top()]--;
            maxHeap.pop();
        }
        while (!minHeap.empty() && toRemove[minHeap.top()] > 0)
        {
            toRemove[minHeap.top()]--;
            minHeap.pop();
        }
    }

    void rebalance()
    {
        cleanHeaps();
        while (sizeLo > sizeHi + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            sizeLo--;
            sizeHi++;
            cleanHeaps();
        }
        while (sizeLo < sizeHi)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            sizeLo++;
            sizeHi--;
            cleanHeaps();
        }
    }

    void insert(int val)
    {
        if (maxHeap.empty() || val <= maxHeap.top())
        {
            maxHeap.push(val);
            sizeLo++;
        }
        else
        {
            minHeap.push(val);
            sizeHi++;
        }
        rebalance();
    }

    void remove(int val)
    {
        if (val <= maxHeap.top())
            sizeLo--;
        else
            sizeHi--;

        toRemove[val]++;
        rebalance();
    }

    long long getDoubleMedian(int d)
    {
        cleanHeaps();
        if (d % 2 != 0)
        {
            return 2LL * maxHeap.top();
        }
        else
        {
            return 1LL * maxHeap.top() + minHeap.top();
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    if (!(cin >> n >> d))
        return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    WindowMedian wm;
    int ans = 0;

    for (int i = 0; i < d; i++)
    {
        wm.insert(a[i]);
    }

    for (int i = d; i < n; i++)
    {
        if (a[i] >= wm.getDoubleMedian(d))
        {
            ans++;
        }

        wm.remove(a[i - d]);
        wm.insert(a[i]);
    }

    cout << ans << "\n";
    return 0;
}