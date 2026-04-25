#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    if (!s.empty() && s[s.length() - 1] == '\n')
    {
        s.erase(s.length() - 1);
    }
    if (!s.empty() && s[s.length() - 1] == '\r')
    {
        s.erase(s.length() - 1);
    }
    if (s.empty())
    {
        cout << "Chuoi rong.";
        return 0;
    }
    int cnt[300] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        cnt[s[i]]++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (cnt[s[i]] > 0)
        {
            cout << s[i] << ": " << cnt[s[i]] << endl;
            cnt[s[i]] = 0;
        }
    }
    return 0;
}