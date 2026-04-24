#include <bits/stdc++.h>
using namespace std;

class window
{
  private:
    multiset<int> low, high;
    int d;

  public:
    window(int size) : d(size) {};
    void canBang();
    void them(int x);
    void xoa(int x);
    int doubleTrungVi();
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    window wd(d);
    int dem = 0;
    for (int i = 0; i < d; i++)
    {
        wd.them(a[i]);
    }

    for (int i = d; i < n; i++)
    {
        if (a[i] >= wd.doubleTrungVi())
        {
            dem++;
        }
        wd.them(a[i]);
        wd.xoa(a[i - d]);
    }

    cout << dem;
}

void window::canBang()
{
    int total_size = low.size() + high.size();
    int need_low = (total_size + 1) / 2;

    if (low.size() < need_low)
    {
        auto it = high.begin();
        low.insert(*it);
        high.erase(it);
    }
    else if (low.size() > need_low)
    {
        auto it = prev(low.end());
        high.insert(*it);
        low.erase(it);
    }
}

void window::them(int x)
{
    auto it = prev(low.end());
    if (low.empty() || x <= *it)
    {
        low.insert(x);
    }
    else
    {
        high.insert(x);
    }
    canBang();
}

void window::xoa(int x)
{
    if (low.find(x) != low.end())
    {
        low.erase(low.find(x));
    }
    else if (high.find(x) != high.end())
    {
        high.erase(high.find(x));
    }
    canBang();
}

int window::doubleTrungVi()
{
    if (d % 2 != 0)
    {
        return 2 * (*prev(low.end()));
    }
    else
    {
        return *prev(low.end()) + *high.begin();
    }
}