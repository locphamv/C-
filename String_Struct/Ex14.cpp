#include <iostream>
#include <string>

using namespace std;

int main()
{

    string s, s1;
    int k;

    getline(cin, s);
    getline(cin, s1);
    cin >> k;

    if (k < 0 || k > (int)s.length())
    {
        cout << "Vi tri " << k << " khong thoa dieu kien." << endl;
    }
    else
    {

        s.insert(k, s1);

        cout << s;
    }

    return 0;
}