#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 9 10
// 1 2
// 1 3
// 1 5
// 2 4
// 3 6
// 3 7
// 5 8
// 6 7
// 8 9
// 9 3

vector<int> adj[1001];
bool visited[1001] = {false};

void inp()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
}

void dfs(int u)
{
    cout << u << " ";
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    inp();
    dfs(1);
}