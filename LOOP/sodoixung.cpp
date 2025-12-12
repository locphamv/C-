#include <iostream>

using namespace std;

bool kiemTra(int n)
{
    int a = n;
    int kq = 0;
    while (n > 0)
    {
        int chuSoCuoi = n % 10;
        n = n / 10;
        kq = kq * 10 + chuSoCuoi;
    }

    if (kq != a)
    {
        return false;
    }
    return true;
}

// bool kiemTra(int n, int dem)
// {

//     int i = 0;
//     if (dem < 0)
//     {
//         return false;
//     }
//     int *a = new int[dem];
//     while (n > 0)
//     {
//         int f = n % 10;
//         if (i < dem)
//         {
//             a[i] = f;
//         }
//         i++;
//         n = n / 10;
//     }

//     for (int i = 0; i < dem; i++)
//     {
//         if (a[i] != a[dem - i - 1])
//         {
//             return false;
//         }
//     }
//     return true;
// }

// int demSoChuSo(int n)
// {
//     int dem = 0;
//     if (n < 0)
//     {
//         return -1;
//     }
//     if (n == 0)
//     {
//         return 1;
//     }
//     while (n > 0)
//     {
//         n = n / 10;
//         dem++;
//     }
//     return dem;
// }

int main()
{
    int n;
    cin >> n;
    // int a = demSoChuSo(n);
    // if(kiemTra(n,a))
    // {

    // }
    if (kiemTra(n))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}