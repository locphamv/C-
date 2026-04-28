#include "NhanVien.h"

int main()
{
    int n;
    cin >> n;
    vector<NhanVien> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    stable_sort(a.begin(), a.end());
    for (auto x : a)
    {
        cout << x;
    }
}