#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, M;
    cin >> n >> M;

    if (M <= 0) {
        return 0;
    }

    vector<int> bucket(M, 0);
    int collisions = 0;

    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;

        int index = ((key % M) + M) % M;

        if (bucket[index] > 0)
        {
            collisions++;
        }

        bucket[index]++;
    }

    int maxBucket = bucket[0];

    for (int i = 1; i < M; i++)
    {
        if (bucket[i] > maxBucket)
        {
            maxBucket = bucket[i];
        }
    }

    for (int i = 0; i < M; i++)
    {
        if (bucket[i] == maxBucket)
        {
            cout << i << endl;
        }
    }

    return 0;
}