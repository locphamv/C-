#include <bits/stdc++.h>
using namespace std;

// o(logn)
// size
// insert
// find
// count
// erase
// multiset
int main()
{
    // set<int> s;
    // s.insert(100);
    // s.insert(200);
    // s.insert(300);
    // s.insert(100);
    // s.insert(200);
    // cout << s.size() << endl;
    // set<int> s;
    // for (int i = 0; i < 10; i++)
    // {
    //     s.insert(i);
    // }
    // // s.erase(5);
    // s.erase(s.find(6));
    // cout << s.size() << endl;
    // if (s.count(5) != 0)
    // {
    //     cout << "Found";
    // }
    // else
    // {
    //     cout << "Not Found";
    // }
    // if (s.find(5) != s.end())
    // {
    //     cout << "Found";
    // }
    // else
    // {
    //     cout << "Not Found";
    // }
    // cout << endl;
    // for (int x : s)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;
    // cout << *s.begin() << endl;
    // cout << *s.rbegin() << endl;

    // int n;
    // cin >> n;
    // set<string> s;
    // cin.ignore();
    // for (int i = 0; i < n; i++)
    // {
    //     string str;
    //     getline(cin, str);
    //     s.insert(str);
    // }

    // cout << s.size() << endl;
    // for (string x : s)
    // {
    //     cout << x << endl;
    // }

    multiset<int> ms;
    ms.insert(100);
    ms.insert(200);
    ms.insert(100);
    cout << ms.size() << endl;
    for (int x : ms)
    {
        cout << x << " ";
    }
    cout << ms.count(100);
    return 0;
}