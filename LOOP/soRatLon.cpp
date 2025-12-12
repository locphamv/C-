#include <iostream>
using namespace std;

int main()
{
    int n;
    double x; // x phai la double de tinh chinh xac
    cin >> n >> x;

    // QUAN TRONG: Khai bao s1, s2, s3 la double nhu yeu cau
    double s1 = 0;
    double s2 = 0;
    double s3 = 0;

    double luyThua = 1;  // x^0
    double giaiThua = 1; // 0!

    for (int i = 0; i <= n; i++)
    {
        // Tinh S1
        s1 += luyThua;

        // Tinh S2
        if (i % 2 == 0)
        {
            s2 += luyThua;
        }

        // Tinh S3
        s3 += luyThua / giaiThua;

        // --- Chuan bi cho vong lap sau ---
        // Nhan doi len de khong phai tinh lai tu dau (tranh tran so)
        luyThua = luyThua * x;
        giaiThua = giaiThua * (i + 1);
    }

    // Xuat ket qua - cout se tu dong dinh dang
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;

    return 0;
}