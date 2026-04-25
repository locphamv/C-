#include <iostream>
#include <cmath> // Thư viện chứa hàm sqrt

using namespace std;

void check(long long n) // Dùng long long để tránh lỗi với số lớn
{
    if (n < 0)
    {
        cout << -1;
        return;
    }

    long long k = sqrt(n); // Lấy phần nguyên căn bậc 2

    if (k * k == n)
    {
        cout << 0; // Là số chính phương
    }
    else
    {
        cout << -1; // Không phải
    }
}

int main()
{
    long long n; // Dùng long long
    cin >> n;
    check(n);
    return 0;
}