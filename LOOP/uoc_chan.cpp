#include <iostream>
#include <cmath>

using namespace std;

long long tinhTongUocChan(int n)
{
    // Nếu n là số lẻ thì không có ước chẵn
    if (n % 2 != 0)
    {
        return -1;
    }

    long long tong = 0;

    // Duyệt từ 1 đến căn bậc 2 của n
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            // Xét ước i
            if (i % 2 == 0)
            {
                tong += i;
            }

            // Xét ước j = n / i
            int j = n / i;
            // Điều kiện i != j để tránh cộng trùng nếu n là số chính phương
            if (i != j)
            {
                if (j % 2 == 0)
                {
                    tong += j;
                }
            }
        }
    }

    return tong;
}

int main()
{
    int n;
    // cout << "Input: "; // Bỏ comment nếu muốn hiện dòng nhắc
    if (cin >> n)
    {
        cout << tinhTongUocChan(n) << endl;
    }
    return 0;
}