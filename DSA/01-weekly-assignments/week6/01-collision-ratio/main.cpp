#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, M;
    cin >> n >> M;

    vector<int> bucket(M, 0);
    int collisions = 0;

    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;

        int index = key % M;

        if (bucket[index] > 0) {
            collisions++;
        }

        bucket[index]++;
    }

    if (collisions * 100 > 33 * n) {
        cout << "BAD";
    } else {
        cout << "GOOD";
    }

    return 0;
}