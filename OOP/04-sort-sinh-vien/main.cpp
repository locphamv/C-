#include "SinhVien.h"
#include <algorithm>
#include <vector>
int main()
{
    vector<SinhVien> v;
    SinhVien tmp;
    while (cin >> tmp)
    {
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for (SinhVien x : v)
    {
        cout << x;
    }
}