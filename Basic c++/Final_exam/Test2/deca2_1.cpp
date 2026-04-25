#include <iostream>
#include <string>
#include <cctype>

using namespace std;
long long tong_chu_so(long long n)
{
    long long sum = 0;
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

    long long tong_gia_tri = 0;

    for (int i = 0; i < ten.length(); i++)
    {

        if (isalpha(ten[i]))
        {

            char ky_tu = tolower(ten[i]);

            int gia_tri = (ky_tu - 'a') % 9 + 1;

            tong_gia_tri += gia_tri;
        }
    }
    while (tong_gia_tri > 11)
    {
        tong_gia_tri = tong_chu_so(tong_gia_tri);
    }

    cout << tong_gia_tri << endl;

    return 0;
}