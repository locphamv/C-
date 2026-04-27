#include <bits/stdc++.h>
using namespace std;

bool isNumber(const string &s)
{
    if (s.empty())
        return false;
    int i = 0;
    if (s[0] == '-')
    {
        if (s.size() == 1)
            return false;
        i = 1;
    }
    for (; i < (int)s.size(); i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

int main()
{
    stack<long long> st;
    string token;

    while (cin >> token)
    {
        if (isNumber(token))
        {
            st.push(stoll(token));
        }
        else if (token == "+" || token == "-" || token == "x" || token == ":")
        {
            if (st.size() < 2)
            {
                cout << "KHONG HOP LE";
                return 0;
            }

            long long b = st.top();
            st.pop();
            long long a = st.top();
            st.pop();
            long long res = 0;

            if (token == "+")
                res = a + b;
            else if (token == "-")
                res = a - b;
            else if (token == "x")
                res = a * b;
            else
            {
                if (b == 0)
                {
                    cout << "KHONG HOP LE";
                    return 0;
                }
                res = a / b;
            }

            st.push(res);
        }
        else
        {
            cout << "KHONG HOP LE";
            return 0;
        }
    }

    if (st.size() != 1)
        cout << "KHONG HOP LE";
    else
        cout << st.top();

    return 0;
}