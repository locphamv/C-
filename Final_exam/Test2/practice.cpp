#include <iostream>
#include <string>
#include <cctype>
using namespace std;

long long tong_chu_so(long long n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    string ten;
    getline(cin, ten);
    long long sum = 0;

    int bang[26] = {1, 2, 3, 4, 5, 6, 7, 8, 9,
                    1, 2, 3, 4, 5, 6, 7, 8, 9,
                    1, 2, 3, 4, 5, 6, 7, 8};

    for (int i = 0; i < ten.length(); i++)
    {
        if (isalpha(ten[i]))
        {
            tolower(ten[i]);
            int vitri = ten[i] - 'a';
            sum += bang[vitri];
        }
    }
    while (sum > 11)
    {
        sum = tong_chu_so(sum);
    }
    cout << sum;
}
