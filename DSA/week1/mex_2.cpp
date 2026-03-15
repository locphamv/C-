#include <iostream>
#include <vector>
using namespace std;

void smallest(vector<int> a, int n)
{

    vector<bool> num(n + 1, false);
    int mex_i = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0 && a[i] <= n)
        {
            num[a[i]] = true;
        }
        while (num[mex_i] == true)
        {
            mex_i++;
        }
        cout << mex_i << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    smallest(a, n);
}