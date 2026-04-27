#include <bits/stdc++.h>
using namespace std;
bool isNumber(string s)
{
    if (s.empty())
        return false;

    int start = 0;
    if (s[0] == '-')
    {
        if (s.length() == 1)
            return false;
        start = 1;
    }

    for (int i = start; i < s.length(); i++)
    {
        if (!isdigit(s[i]))
            return false;
    }

    return true;
}

int main()
{
    stack<int> nums;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        if (isNumber(x))
        {
            nums.push(stoi(x));
        }
        else
        {
            int a = nums.top();
            nums.pop();
            int b = nums.top();
            nums.pop();

            if (x == "+")
            {
                nums.push(b + a);
                continue;
            }
            if (x == "-")
            {
                nums.push(b - a);
                continue;
            }
            if (x == "/")
            {
                nums.push(b / a);
                continue;
            }
            if (x == "*")
            {
                nums.push(b * a);
            }
        }
    }

    cout << nums.top();
}