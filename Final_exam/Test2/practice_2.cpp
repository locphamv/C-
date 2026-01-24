#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[300][300];
    int b[300];
    bool ma_tran_hoan_vi = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] != 0 && a[i][j] != 1)
            {
                ma_tran_hoan_vi = false;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    if (ma_tran_hoan_vi)
    {
        for (int i = 0; i < n; i++)
        {
            int tong_hang = 0;
            for (int j = 0; j < n; j++)
            {
                tong_hang += a[i][j];
            }
            if (tong_hang != 1)
            {
                ma_tran_hoan_vi = false;
                break;
            }
        }
    }
    if (ma_tran_hoan_vi)
    {
        for (int i = 0; i < n; i++)
        {
            int tong_cot = 0;
            for (int j = 0; j < n; j++)
            {
                tong_cot += a[j][i];
            }
            if (tong_cot != 1)
            {
                ma_tran_hoan_vi = false;
                break;
            }
        }
    }

    if (!ma_tran_hoan_vi)
    {
        cout << "Khong phai ma tran hoan vi";
        return 0;
    }
    int res[300];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += b[j] * a[j][i];
        }
        res[k] = sum;
        k++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << (i == n - 1 ? "" : " ");
    }
}