#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Hàm chuyển đổi 1 số nguyên sang La Mã
string DoiSangLaMa(int n)
{
    // 1. Kiểm tra điều kiện (Số La Mã thường chỉ tính từ 1 đến 3999)
    if (n <= 0)
        return "";

    // 2. Bảng quy đổi (Xếp giảm dần quan trọng nhất!)
    int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string ketqua = "";

    // 3. Duyệt qua từng mốc giá trị
    for (int i = 0; i < 13; i++)
    {
        // Trong khi n vẫn lớn hơn hoặc bằng mốc hiện tại
        while (n >= val[i])
        {
            ketqua += sym[i]; // Cộng ký tự vào kết quả
            n -= val[i];      // Trừ bớt giá trị đi
        }
    }
    return ketqua;
}

int main()
{
    int n;
    // cout << "Nhap so luong phan tu n: ";
    cin >> n;

    // Nhập dãy số
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Xuất dãy số La Mã
    for (int i = 0; i < n; i++)
    {
        cout << DoiSangLaMa(a[i]) << endl;
    }

    return 0;
}