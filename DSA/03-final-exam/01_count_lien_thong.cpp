#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    vector<int> componentSize;

    for (int start = 1; start < n; start++) {
        if (visited[start]) {
            continue;
        }
        queue<int> q;
        q.push(start);
        visited[start] = true;
        int size = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            size++;

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        componentSize.push_back(size);
    }
    sort(componentSize.begin(), componentSize.end(), greater<int>());
    cout << componentSize.size() << "\n";
    for (int size : componentSize) {
        cout << size << " ";
    }
    return 0;
}