#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int findFirstPos(int k) {
    int l = 0;
    int r = arr.size() - 1;
    int ans = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (k == arr[m]) {
            ans = m + 1;
            r = m - 1;
        } else if (k < arr[m]) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        int tmp;
        cin >> tmp;
        cout << findFirstPos(tmp) << '\n';
    }
    return 0;
}