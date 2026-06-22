#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, m; // n: số đỉnh, m: số cạnh
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Nếu là đồ thị có hướng, bỏ dòng này
    }

    int connected_components_count = 0;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            connected_components_count++; // Gặp một đỉnh chưa thăm -> thành phần liên thông mới
            dfs(i);
        }
    }

    cout << "So thanh phan lien thong: " << connected_components_count << endl;

    return 0;
}
