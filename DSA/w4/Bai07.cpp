#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> count(1000001, 0);
    int n, k;
    cin >> n;
    cin >> k;

    priority_queue<pair<int, int>> pq;
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

    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        if (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
    }

    sort(ans.begin(), ans.end());
    for (auto x : ans)
    {
        cout << x << "\n";
    }
}

