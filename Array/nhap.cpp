#include <iostream>
using namespace std;
void nhapMang(int a[], int n)
{
    int *arr = a;
    int *parr = arr;
    for (int i = 0; i < n; i++)
    {
        cin >> parr[i];
    }
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    nhapMang(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << *(a + i) << " ";
    }

    return 0;
}