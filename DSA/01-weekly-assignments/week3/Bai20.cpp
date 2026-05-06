#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    unordered_map<int, pair<int, int>> pos;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        auto it = pos.find(x);
        if (it == pos.end()) {
            pos[x] = {i, i};
        } else {
            it->second.second = i;
        }
    }

    while (q--) {
        string tmp;
        int type, y;
        cin >> tmp >> type >> y;

        auto it = pos.find(y);
        if (it == pos.end()) {
            cout << -1 << '\n';
        } else {
            if (type == 1) cout << it->second.first << '\n';
            else cout << it->second.second << '\n';
        }
    }

    return 0;
}