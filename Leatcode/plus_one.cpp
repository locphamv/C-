#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        for (int i = (int)digits.size() - 1; i >= 0; --i)
        {
            if (digits[i] < 9)
            {
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

static void printVec(const vector<int> &v)
{
    cout << "[";
    for (int i = 0; i < (int)v.size(); ++i)
    {
        cout << v[i];
        if (i + 1 < (int)v.size())
            cout << ",";
    }
    cout << "]";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    // Test 1
    vector<int> a{1, 2, 3};
    auto r1 = sol.plusOne(a);
    cout << "Input: [1,2,3] -> Output: ";
    printVec(r1);
    cout << "\n";

    // Test 2
    vector<int> b{4, 3, 2, 1};
    auto r2 = sol.plusOne(b);
    cout << "Input: [4,3,2,1] -> Output: ";
    printVec(r2);
    cout << "\n";

    // Test 3
    vector<int> c{9};
    auto r3 = sol.plusOne(c);
    cout << "Input: [9] -> Output: ";
    printVec(r3);
    cout << "\n";

    return 0;
}
