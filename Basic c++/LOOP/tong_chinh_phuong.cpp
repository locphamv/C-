#include <iostream>

using namespace std;

long long tinhTongUocChinhPhuong(int n)
{
    long long tong = 0;

    // Duyệt i từ 1, tạo số chính phương sq = i*i
    // Điều kiện lặp: i*i <= n
    for (long long i = 1; i * i <= n; i++)
    {
        long long sq = i * i;

        if (n % sq == 0)
        {
            tong += sq;
        }
    }

    return tong;
}

int main()
{
    int n;
    // cout << "Input: ";
    if (cin >> n)
    {
        cout << tinhTongUocChinhPhuong(n) << endl;
    }
    return 0;
}