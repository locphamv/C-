#include <iostream>

using namespace std;

void NhapMang(int a[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int TimSoLonNhatVaDem(int a[], int n)
{
    int max1 = a[0]; // khoi tao
    int dem = 1;

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max1)
        {
            max1 = a[i]; // Cập nhật số lớn nhất mới
            dem = 1;
            // Reset lại biến đếm vì tìm thấy kỷ lục mới
        }
        else if (a[i] == max1) // neu a[i] khong lon hon ma bang thi ki luc nay cong them 1
        {
            dem++;
        }
    }

    cout << max1 << endl;
    cout << dem;
    return dem;
}

int main()
{
    int n;
    cin >> n;
    int A[10005];
    NhapMang(A, n);
    TimSoLonNhatVaDem(A, n);
    return 0;
}