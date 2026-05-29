#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, M;
    cin >> M >> n;

    if (M <= 0)
    {
        return 0;
    }

    vector<int> bucket(M, 0);
    int collision = 0;
    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;

        int index = key % M;
        int goc = index;
        int j = 0;
        while (j < M && bucket[index] != 0)
        {
            index = (goc + j) % M;
            j++;
            collision++;
        }
        if (j < M)
        {
            bucket[index]++;
        }
    }

    cout << collision;
    return 0;
}