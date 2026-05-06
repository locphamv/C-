#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    string t;
    cin >> s;
    cin >> t;

    stack<char> s1;
    stack<char> t1;

    int m = s.length();
    int n = t.length();

    for (int i = 0; i < m; i++)
    {
        if (s[i] != '#')
        {
            s1.push(s[i]);
        }
        else if (!s1.empty())
        {
            s1.pop();
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (t[i] != '#')
        {
            t1.push(t[i]);
        }
        else if (!t1.empty())
        {
            t1.pop();
        }
    }

    while (!s1.empty() && !t1.empty())
    {
        if (s1.top() != t1.top())
        {
            cout << "NO";
            return 0;
        }
        s1.pop();
        t1.pop();
    }
    if (!s1.empty() || !t1.empty())
    {
        cout << "NO";
        return 0;
    }
    cout << "YES";
}