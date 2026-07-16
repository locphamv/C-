#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<int, int> frequency;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        frequency[x]++;
    }

    int q;
    cin >> q;

    while (q--) {
        int x;
        cin >> x;
        auto it = frequency.find(x);
        if (it == frequency.end()) {
            cout << 0 << "\n";
        } else {
            cout << it->second << '\n';
        }
    }

    return 0;
}