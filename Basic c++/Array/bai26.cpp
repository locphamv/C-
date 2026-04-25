#include <iostream>
using namespace std;

void solve(int *arr, int n);

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    solve(arr, n);

    return 0;
}

void solve(int *arr, int n)
{
    
    int cnt[105];
    for (int i = 0; i < 105; i++)
        cnt[i] = 0;

    // 2. Đếm số lần xuất hiện của từng số trong mảng arr
    for (int i = 0; i < n; i++)
    {
        int val = arr[i];
        cnt[val]++;
    }

    // 3. Tìm kết quả lớn nhất
    int max_len = 0;

    // Duyệt từ 0 đến 100 để kiểm tra từng cặp (i, i+1)
    for (int i = 0; i <= 100; i++)
    {
        // Tổng số phần tử của cặp số i và i+1
        int current = cnt[i] + cnt[i + 1];

        // Tự kiểm tra max (vì không có thư viện algorithm)
        if (current > max_len)
        {
            max_len = current;
        }
    }

    cout << max_len;
}