#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    if (s.empty())
    {
        cout << "Chuoi rong.";
        return 0;
    }

    int i = 0;
    int j = s.length() - 1;
    while (i < j)
    {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }

    int start = 0;
    for (int k = 0; k <= s.length(); k++)
    {

        if (s[k] == ' ' || s[k] == '\0')
        {
            int end = k - 1;
            while (start < end)
            {
                char temp = s[start];
                s[start] = s[end];
                s[end] = temp;
                start++;
                end--;
            }
            start = k + 1;
        }
    }
    cout << s;
    return 0;
}