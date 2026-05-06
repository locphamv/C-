#include <bits/stdc++.h>
using namespace std;

void printArray(const vector<long long> &a)
{
    for (int i = 0; i < (int)a.size(); i++)
    {
        if (i > 0)
            cout << " ";
        cout << a[i];
    }
    cout << "\n";
}

void printHeapState(const vector<long long> &a, int heapSize)
{
    for (int i = 0; i < heapSize; i++)
    {
        if (i > 0)
            cout << " ";
        cout << a[i];
    }

    if (heapSize < (int)a.size())
    {
        cout << " | ";
        for (int i = heapSize; i < (int)a.size(); i++)
        {
            if (i > heapSize)
                cout << " ";
            cout << a[i];
        }
    }
    cout << "\n";
}

void heapify(vector<long long> &a, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void buildHeap(vector<long long> &a)
{
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
}

int main()
{
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Mang truoc khi sap xep:\n";
    printArray(a);
    cout << "\n";

    cout << "Sap xep:\n";

    buildHeap(a);
    cout << "Mang sau khi BuildHeap: ";
    printArray(a);

    for (int heapSize = n; heapSize > 1; heapSize--)
    {
        cout << "Swap " << a[0] << " va " << a[heapSize - 1] << "\n";
        swap(a[0], a[heapSize - 1]);
        cout << "\n";

        heapify(a, heapSize - 1, 0);

        cout << "Mang sau khi heapify voi n = " << (heapSize - 1) << ": ";
        printHeapState(a, heapSize - 1);
        }

    cout << "Mang sau khi sap xep:\n";
    printArray(a);

    return 0;
}