#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;

    vector<long long> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (n < 2) {
        cout << -1;
        return 0;
    }

    sort(arr.begin(), arr.end());

    int left = 0;
    int right = n - 1;

    int bestLeft = 0;
    int bestRight = n - 1;
    long long bestDiff = LLONG_MAX;

    while (left < right) {
        long long sum = arr[left] + arr[right];
        long long diff = llabs(sum - k);

        if (diff < bestDiff) {
            bestDiff = diff;
            bestLeft = left;
            bestRight = right;
        }

        if (sum == k) {
            break;
        }

        if (sum > k) {
            right--;
        } else {
            left++;
        }
    }

    cout << arr[bestLeft] << ' ' << arr[bestRight];

    return 0;
}