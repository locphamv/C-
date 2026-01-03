#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string addBinary(string a, string b)
{
    string result = "";
    int m = a.length() - 1;
    int n = b.length() - 1;
    int carry = 0;
    while (m >= 0 || n >= 0)
    {
        int sum = carry;
        if (m >= 0)
            sum += (a[m--] - '0');
        if (n >= 0)
            sum += (b[n--] - '0');
        carry = (sum > 1) ? 1 : 0;
        result += (sum % 2 + '0');
    }
    if (carry)
        result.push_back('1');
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string a, b;
    cin >> a >> b;

    cout << addBinary(a, b);
    return 0;
}