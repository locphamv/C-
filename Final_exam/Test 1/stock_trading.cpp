#include <iostream>
using namespace std;

int canSell(int a[], int i, int m)
{
    int dem = 0;

    for (int j = 0; j < m; j++)
    {
        if (i >= a[j])
        {
            dem++;
        }
    }
    return dem;
}

int canBuy(int b[], int i, int m)
{
    int dem = 0;

    for (int j = 0; j < m; j++)
    {
        if (i <= b[j])
        {
            dem++;
        }
    }
    return dem;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int *a = new int[n];
    int *b = new int[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int l = 1;
    int r = 1000000000;
    int ans = r + 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (canSell(a, mid, n) >= canBuy(b, mid, m))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << ans;
    delete[] a;
    delete[] b;
    return 0;
}