#include <iostream>
using namespace std;

void Output(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

void InsertionSortDesc(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        cout << "i = " << i << "\n";
        cout << "Mang truoc khi xu ly: ";
        Output(a, n);

        int x = a[i];
        cout << "Phan tu dang xet A[" << i << "] = " << x << "\n";

        int k = i - 1;
        while (k >= 0 && a[k] < x)
        {
            a[k + 1] = a[k];
            k--;
        }

        a[k + 1] = x;

        cout << "Chen " << x << " vao vi tri k = " << k + 1 << "\n";
        cout << "Mang sau khi xu ly: ";
        Output(a, n);
        cout << "\n";
    }
}

int main()
{
    int n;
    cin >> n;

    int a[205];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Mang truoc khi sap xep:\n";
    Output(a, n);
    cout << "\n";

    cout << "Sap xep:\n";
    InsertionSortDesc(a, n);

    cout << "Mang sau khi sap xep:\n";
    Output(a, n);

    return 0;
}