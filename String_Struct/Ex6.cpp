#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    string result = "";
    int n = s.length();
    int i = 0;
    while (i < n)
    {
        while (i < n && s[i] == ' ')
        {
            i++;
        }
        if (i == n)
        {
            break;
        }
        if (result.length() > 0)
        {
            result += ' ';
        }
        result += toupper(s[i]);
        i++;
        while (i < n && s[i] != ' ')
        {
            result += tolower(s[i]);
            i++;
        }
    }
    cout << result << endl;
    return 0;
}