#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<int, int> frequency;
    vector<int> baseArr(n);
    for (int i = 0; i < n; i++) {

        cin >> baseArr[i];
        frequency[baseArr[i]]++;
    }
    for (int x : baseArr) {
        if (frequency[x] == 1) {
            cout << x;
            return 0;
        }
    }

    return 0;
}