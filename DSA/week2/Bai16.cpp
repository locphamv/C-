#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    unordered_set<string> s;
    for (int i = 0; i < N; i++)
    {
        string code;
        cin >> code;
        s.insert(code);
    }

    cout << s.size();

    return 0;
}