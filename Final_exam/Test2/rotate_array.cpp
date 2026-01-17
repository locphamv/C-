#include <iostream>
using namespace std;

void rotate(int a[], int n, int q)
{
    for (int i = 0; i < q; i++)
    {
        int tmp = a[n - 1];
        for (int i = n - 1; i > 0; i--)
        {
            a[i] = a[i - 1];
        }

        a[0] = tmp;
    }
}

int main()
{
    int n, k, q;
    cin >> n >> k >> q;
    int a[100];
    int b[100];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < q; i++)
    {
        cin >> b[i];
    }

    rotate(a, n, k);

    for (int i = 0; i < q; i++)
    {
        cout << a[b[i]] << " ";
    }
}
