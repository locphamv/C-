#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        indegree[v]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0)
            pq.push(i);
    }

    vector<int> order;

    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();

        order.push_back(u);

        for (int v : adj[u]) {
            indegree[v]--;

            if (indegree[v] == 0)
                pq.push(v);
        }
    }

    if ((int)order.size() != n) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for (int vertex : order) {
        cout << vertex << ' ';
    }

    return 0;
}