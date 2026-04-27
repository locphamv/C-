#include <bits/stdc++.h>
using namespace std;

string makeGood(string s)
{
    string stack_str = "";

    for (char c : s)
    {

        if (!stack_str.empty() && abs(stack_str.back() - c) == 32)
        {
            stack_str.pop_back();
        }
        else
        {
            stack_str.push_back(c);
        }
    }

    return stack_str;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (cin >> s)
    {
        cout << makeGood(s) << "\n";
    }

    return 0;
}