#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size, window;
    cin >> window >> size;
    queue<int> q;
    int tong = 0;
    for (int i = 1; i <= size; i++)
    {
        int data;
        cin >> data;
        tong += data;
        q.push(data);

        if (q.size() > window)
        {
            tong -= q.front();
            q.pop();
        }

        if (i <= window)
        {
            cout << setprecision(5) << fixed << tong * 1.0 / i << "\n";
        }
        else
        {
            cout << setprecision(5) << fixed << tong * 1.0 / window << "\n";
        }
    }
}