#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    long long n, k, p, q; // Dùng long long đề phòng n lớn (10^9)
    if (!(cin >> n >> k >> p >> q))
        return 0;

    // 1. Đổi vị trí Alice ra số thứ tự (Index)
    long long idxAlice = (p - 1) * 2 + q;

    // 2. Tạo 2 ứng cử viên cho Bob
    long long idxBobTruoc = idxAlice - k;
    long long idxBobSau = idxAlice + k;

    long long finalRow = -1, finalCol = -1;
    long long minDistance = 1000000000; // Khởi tạo khoảng cách vô cùng lớn

    // 3. Xét trường hợp ngồi TRƯỚC
    if (idxBobTruoc >= 1)
    {
        long long row = (idxBobTruoc - 1) / 2 + 1;
        long long col = (idxBobTruoc - 1) % 2 + 1;
        long long dist = abs(row - p);

        // Cập nhật kết quả
        minDistance = dist;
        finalRow = row;
        finalCol = col;
    }

    // 4. Xét trường hợp ngồi SAU
    if (idxBobSau <= n)
    {
        long long row = (idxBobSau - 1) / 2 + 1;
        long long col = (idxBobSau - 1) % 2 + 1;
        long long dist = abs(row - p);

        // Logic chọn:
        // Nếu chưa tìm được ai (finalRow == -1) -> Chọn luôn
        // Hoặc nếu khoảng cách này NHỎ HƠN khoảng cách cũ -> Chọn cái mới
        // Lưu ý: Nếu khoảng cách BẰNG NHAU, đề bảo chọn bàn phía trước.
        // Vì ta xét "Trước" rồi mới đến "Sau", nên nếu bằng nhau ta KHÔNG cập nhật, giữ nguyên cái "Trước".
        if (finalRow == -1 || dist < minDistance)
        {
            finalRow = row;
            finalCol = col;
        }
    }

    // 5. Xuất kết quả
    if (finalRow == -1)
    {
        cout << -1;
    }
    else
    {
        cout << finalRow << " " << finalCol;
    }

    return 0;
}