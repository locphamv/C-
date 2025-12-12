
#include <iostream>
using namespace std;

void NhapMang(int *, int);
void XuatMang(int *, int);
void GopMang(int *, int, int *, int, int *, int);

int main()
{
    int n;
    cin >> n;
    int A[n];
    NhapMang(A, n);

    int m;
    cin >> m;
    int B[m];
    NhapMang(B, m);

    int mn = m + n;
    int C[mn];

    GopMang(A, n, B, m, C, mn);

    XuatMang(C, mn);
    return 0;
}

void NhapMang(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void XuatMang(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void GopMang(int *a, int m, int *b, int n, int *c, int mn)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
        }
        k++;
    }
    while (i < m)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j < n)
    {
        c[k] = b[j];
        j++;
        k++;
    }
}