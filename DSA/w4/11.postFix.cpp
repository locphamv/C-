#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

bool isOperator(string x)
{
    return (x == "+" || x == "-" || x == "x" || x == ":");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<long long> st;
    string x;

    while (cin >> x)
    {
        if (!isOperator(x))
        {
            try
            {
                st.push(stoll(x));
            }
            catch (...)
            {
                cout << "KHONG HOP LE\n";
                return 0;
            }
        }
        else
        {
            if (st.size() < 2)
            {
                cout << "KHONG HOP LE\n";
                return 0;
            }

            long long a = st.top();
            st.pop();
            long long b = st.top();
            st.pop();

            if (x == "+")
            {
                st.push(b + a);
            }
            else if (x == "-")
            {
                st.push(b - a);
            }
            else if (x == "x")
            {
                st.push(b * a);
            }
            else if (x == ":")
            {
                if (a == 0)
                {
                    cout << "KHONG HOP LE\n";
                    return 0;
                }
                st.push(b / a);
            }
        }
    }

    if (st.size() == 1)
    {
        cout << st.top() << "\n";
    }
    else
    {
        cout << "KHONG HOP LE\n";
    }

    return 0;
}