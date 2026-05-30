#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, M;
    cin >> n >> M;

    if (M <= 0)
    {
        return 0;
    }

    vector<int> bucket(M, 0);
    for (int j = 0; j < n; j++)
    {
        int key;
        cin >> key;

        int goc = key % M;
        for (int i = 0; i < M; i++)
        {
            int index = (goc + i) % M;

            if (bucket[index] == 0)
            {
                bucket[index]++;
                break;
            }
            else
            {
                bucket[index]++;
            }
        }
    }

    int maxBucket = bucket[0];
    for (int i = 1; i < M; i++)
    {
        if (bucket[i] > maxBucket)
        {
            maxBucket = bucket[i];
        }
    }

    if (maxBucket == 0)
    {
        return 0;
    }

    for (int i = 0; i < M; i++)
    {
        if (bucket[i] == maxBucket)
        {
            cout << i << " ";
        }
    }

    return 0;
}