#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int bestL = 0;
    int bestR = n - 1;
    int bestI = 0;
    int bestDiff = 99999999;
    for (int i = 0; i < n - 2; i++) {
        int L = i + 1;
        int R = n - 1;
        while (L < R) {
            long long sum = arr[L] + arr[R] + arr[i];
            int diff = abs(sum - k);
            if (diff < bestDiff) {
                bestDiff = diff;
                bestL = L;
                bestR = R;
                bestI = i;
            }
            if (sum == k) {
                bestL = L;
                bestR = R;
                cout << arr[L] << " " << arr[i] << arr[R];
                return 0;
            } else if (sum < k) {
                L++;
            } else {
                R--;
            }
        }
    }
    cout << arr[bestL] << " " << arr[bestI] << " " << arr[bestR];
    return 0;
}