#include <bits/stdc++.h>
using namespace std;

int soTrongKhoang(const vector<int> &arr, int L, int R) {
    auto it1 = lower_bound(arr.begin(), arr.end(), L);
    auto it2 = upper_bound(arr.begin(), arr.end(), R);
    return it2 - it1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int q;
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        cout << soTrongKhoang(arr, L, R) << '\n';
    }
    return 0;
}