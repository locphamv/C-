#include <iostream>
using namespace std;
#define MAX 16

void Nhapmang(int a[][MAX], int &n);
void Xuatmang(int a[][MAX], int n);

void Nhapmang(int a[][MAX], int &n)
{
    cin >> n;
}

int traVeFibo(int sofibothu)
{
    int f1 = 1;
    int f2 = 1;
    int fn = f2 + f1;
    if (sofibothu == 1 || sofibothu == 2)
        return f1;
    for (int i = 0; i < sofibothu - 3; i++)
    {
        f1 = f2;
        f2 = fn;
        fn = f1 + f2;
    }
    return fn;
}

void Xuatmang(int a[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << traVeFibo(i + j + 1) << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    int a[MAX][MAX];
    Nhapmang(a, n);
    Xuatmang(a, n);
}