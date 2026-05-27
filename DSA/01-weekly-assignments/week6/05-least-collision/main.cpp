#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, M;
    cin >> n >> M;

    if (M <= 0)
    {
        return 0;
    }

    vector<int> bucket(M, 0);

    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;

        int index = key % M;
        bucket[index]++;
    }

    int minCollision = -1;

    for (int i = 0; i < M; i++)
    {
        if (bucket[i] >= 2)
        {
            int collision = bucket[i] - 1;

            if (minCollision == -1 || collision < minCollision)
            {
                minCollision = collision;
            }
        }
    }

    if (minCollision == -1)
    {
        return 0;
    }

    for (int i = 0; i < M; i++)
    {
        if (bucket[i] >= 2 && bucket[i] - 1 == minCollision)
        {
            cout << i << " ";
        }
    }

    return 0;
}