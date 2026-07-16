#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    set<int> check;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin>>tmp;
        auto it = check.find(k-tmp);
        if (it != check.end()) {
            cout << *it << " " <<tmp;
            return 0;
        }
        check.insert(tmp);
    }
    cout<<-1;
    return 0;
}