#include <bits/stdc++.h>
using namespace std;

struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.first != b.first)
        {
            return a.first < b.first;
        }
        return a.second > b.second;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> count(1000001, 0);
    int n, k;
    cin >> n;
    cin >> k;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    vector<int> appeared;
    vector<int> data(n);

    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
        if (count[data[i]] == 0)
        {
            appeared.push_back(data[i]);
        }
        count[data[i]]++;
    }

    for (auto x : appeared)
    {
        pq.push({count[x], x});
    }

    for (int i = 0; i < k; i++)
    {
        if (!pq.empty())
        {
            cout << pq.top().second << "\n";
            pq.pop();
        }
    }
}