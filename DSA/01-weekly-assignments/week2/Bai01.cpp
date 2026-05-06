#include <iostream>
using namespace std;

int n;
int a[205];

void Output(int *a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

void QuickSort(int *a, int l, int r)
{
    if (l >= r)
        return;

    cout << "Truoc: ";
    Output(a, n);

    int x = a[(l + r) / 2];
    cout << "Left=" << l << " - Right=" << r << " - Pivot=" << x << "\n";

    int i = l, j = r;
    while (i < j)
    {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    cout << "Sau: ";
    Output(a, n);
    cout << "\n";

    QuickSort(a, l, j);
    QuickSort(a, i, r);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Mang truoc khi sap xep:\n";
    Output(a, n);
    cout << "\n";

    cout << "Sap xep:\n";
    QuickSort(a, 0, n - 1);

    cout << "Mang sau khi sap xep:\n";
    Output(a, n);

    return 0;
}