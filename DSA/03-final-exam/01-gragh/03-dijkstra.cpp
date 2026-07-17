#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Edge {
    int to;
    ll weight;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;

        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int s, t;
    cin >> s >> t;

    const ll INF = numeric_limits<ll>::max() / 4;

    vector<ll> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [currentDist, u] = pq.top();
        pq.pop();

        if (currentDist != dist[u])
            continue;

        for (const Edge &edge : adj[u]) {
            int v = edge.to;
            ll w = edge.weight;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;

                pq.push({dist[v], v});
            }
        }
    }

    if (dist[t] == INF) {
        cout << -1;
        return 0;
    }

    cout << dist[t] << '\n';

    vector<int> path;

    for (int current = t; current != -1; current = parent[current]) {
        path.push_back(current);
    }

    reverse(path.begin(), path.end());

    for (int vertex : path) {
        cout << vertex << ' ';
    }

    return 0;
}