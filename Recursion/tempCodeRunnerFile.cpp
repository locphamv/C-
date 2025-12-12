#include <iostream>
using namespace std;

int row(int n, int k, int p, int q)
{

    if (k % 2 == 0)
    {
        if (p - k / 2 >= 1)
        {
            return p - k / 2;
        }
        else
        {
            return p + k / 2;
        }
    }
    else
    {
        if (p - k / 2 + 1 >= 1)
        {
            return p - k / 2 - 1;
        }
        else
            return p + k / 2 + 1;
    }
}

int col(int n, int k, int p, int q)
{
    if (k % 2 == 0)
    {
        if (q == 1)
        {
            return 1;
        }
        if (q == 2)
        {
            return 2;
        }
    }
    if (k % 2 != 0)
    {
        {
            if (q == 1)
            {
                return 2;
            }
            if (q == 2)
            {
                return 1;
            }
        }
    }

    return 1;
}

int main()
{
    int n, k, p, q;
    cin >> n >> k >> p >> q;
    if (k > n || k < 2)
    {
        cout << -1;
        return 0;
    }
    if (p < 1 || p > (n + 1) / 2)
    {
        cout << -1;
        return 0;
    }
    if (q != 1 && q != 2)
    {
        cout << -1;
        return 0;
    }
    cout << row(n, k, p, q) << " " << col(n, k, p, q);
    return 0;
}