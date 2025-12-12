#include <iostream>
using namespace std;

void nhapMang(float a[][100], int &dong, int &cot)
{

    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            cin >> a[i][j];
        }
    }
}

void xuatMang(float a[][100], int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int dong, cot;
    float a[100][100];
    cin >> dong >> cot;
    nhapMang(a, dong, cot);
    xuatMang(a, dong, cot);

    return 0;
}