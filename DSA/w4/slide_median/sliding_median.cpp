#include <bits/stdc++.h>
using namespace std;

class SlidingMedian
{
  private:
    multiset<long long> low, high; // low nửa nhỏ, high nửa trái
    int d;

    void rebalance()
    {
        int total = (int)low.size() + (int)high.size();
        int needLow = (total + 1) / 2;

        while ((int)low.size() > needLow)
        {
            auto it = prev(low.end());
            high.insert(*it);
            low.erase(it);
        }

        while ((int)low.size() < needLow)
        {
            auto it = high.begin();
            low.insert(*it);
            high.erase(it);
        }
    }

  public:
    SlidingMedian(int windowSize) : d(windowSize)
    {
    }

    void add(long long x)
    {
        if (low.empty() || x <= *prev(low.end()))
        {
            low.insert(x);
        }
        else
        {
            high.insert(x);
        }
        rebalance();
    }

    void remove(long long x)
    {
        auto itLow = low.find(x);
        if (itLow != low.end())
        {
            low.erase(itLow);
        }
        else
        {
            auto itHigh = high.find(x);
            if (itHigh != high.end())
                high.erase(itHigh);
        }
        rebalance();
    }

    long long twiceMedian() const
    {
        if (d % 2 == 1)
        {
            return 2LL * (*prev(low.end()));
        }
        else
        {
            return (*prev(low.end())) + (*high.begin());
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    SlidingMedian sm(d);

    for (int i = 0; i < d; i++)
    {
        sm.add(a[i]);
    }

    int ans = 0;

    for (int i = d; i < n; i++)
    {
        if (a[i] >= sm.twiceMedian())
        {
            ans++;
        }

        sm.remove(a[i - d]); // bỏ phần tử cũ ra khỏi cửa sổ
        sm.add(a[i]);        // thêm phần tử mới vào cửa sổ
    }
    cout << ans << '\n';
    return 0;
}


// Sliding Median - 2 multiset
// low  = nửa nhỏ
// high = nửa lớn
// invariant:
//   - low giữ (window_size + 1) / 2 phần tử nhỏ hơn
//   - mọi phần tử trong low <= mọi phần tử trong high
//
// add(x):
//   - nếu low rỗng hoặc x <= max(low) -> vào low
//   - ngược lại -> vào high
//   - rồi rebalance
//
// remove(x):
//   - tìm trong low, không có thì tìm trong high
//   - xóa đúng 1 bản sao
//   - rồi rebalance
//
// rebalance():
//   - nếu low thừa -> chuyển max(low) sang high
//   - nếu low thiếu -> chuyển min(high) sang low
//
// median:
//   - d lẻ  -> max(low)
//   - d chẵn -> (max(low) + min(high)) / 2
//   - để tránh double:
//       + d lẻ  -> 2 * median = 2 * max(low)
//       + d chẵn -> 2 * median = max(low) + min(high)
//
// main flow:
//   - tạo cửa sổ đầu gồm d phần tử
//   - for i từ d đến n-1:
//       check a[i] với 2 * median
//       remove a[i-d]
//       add a[i]