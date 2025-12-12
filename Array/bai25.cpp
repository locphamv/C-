#include <iostream>

void nhapMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
}

bool kiemTra(int a[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        if (a[i] != a[n - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;

    std::cin >> n;
    int a[10005];
    nhapMang(a, n);
    if (kiemTra(a, n))
    {
        std::cout << "array is palindrome";
    }
    else
    {
        std::cout << "array is not palindrome";
    }
    return 0;
}