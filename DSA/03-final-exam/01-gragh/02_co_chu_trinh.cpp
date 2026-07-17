#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<bool> visited;
bool dfs(int u, int parent) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (dfs(v, u)) {
                return true;
            }
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.resize(n + 1);
    visited.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool hasCycle = false;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}