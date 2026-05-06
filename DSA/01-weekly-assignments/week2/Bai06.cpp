#include <iostream>
#include <vector>
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

void mergeRuns(const vector<long long> &B, const vector<long long> &C,
               vector<long long> &A, int k)
{
    int i = 0, j = 0, p = 0;
    int nb = B.size(), nc = C.size();

    while (i < nb && j < nc)
    {
        int endB = min(i + k, nb);
        int endC = min(j + k, nc);

        int x = i, y = j;

        while (x < endB && y < endC)
        {
            if (B[x] >= C[y])
                A[p++] = B[x++];
            else
                A[p++] = C[y++];
        }

        while (x < endB)
            A[p++] = B[x++];
        while (y < endC)
            A[p++] = C[y++];

        i = endB;
        j = endC;
    }

    while (i < nb)
        A[p++] = B[i++];
    while (j < nc)
        A[p++] = C[j++];
}

int main()
{
    int n;
    cin >> n;

    vector<long long> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << "Mang truoc khi sap xep:\n";
    printArray(A);
    cout << "\n";

    cout << "Sap xep:\n";

    for (int k = 1; k < n; k *= 2)
    {
        cout << "k = " << k << "\n";
        cout << "Mang A (truoc khi chia): ";
        printArray(A);

        vector<long long> B, C;
        bool toB = true;
        int i = 0;

        while (i < n)
        {
            int end = min(i + k, n);
            if (toB)
            {
                for (int j = i; j < end; j++)
                    B.push_back(A[j]);
            }
            else
            {
                for (int j = i; j < end; j++)
                    C.push_back(A[j]);
            }
            toB = !toB;
            i = end;
        }

        cout << "Mang B: ";
        printArray(B);

        cout << "Mang C: ";
        printArray(C);

        mergeRuns(B, C, A, k);

        cout << "Mang A (sau khi gop): ";
        printArray(A);
        cout << "\n";
    }

    cout << "Mang sau khi sap xep:\n";
    printArray(A);

    return 0;
}