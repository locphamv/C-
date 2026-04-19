#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> nums;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "push")
        {
            int x;
            cin >> x;
            nums.push(x);
            continue;
        }
        if (s == "empty")
        {
            cout << (nums.empty() ? "true" : "false")<<"\n" ;
            continue;
        }
        if (s == "peek")
        {
            if (!nums.empty())
            {
                cout << nums.front()<<"\n";
                continue;
            } 
        }
        if (s == "pop")
        {
            if (!nums.empty())
            {
                cout<<nums.front()<<"\n";
                nums.pop();
                continue;
            }
        }
    }

}