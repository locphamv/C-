#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    if (!(cin >> n))
        return 0;
    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    vector<int> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    bool la_ma_tran_hoan_vi = true;

    for (int i = 0; i < n; i++)
    {
        int tong_hang = 0;
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != 0 && matrix[i][j] != 1)
            {
                la_ma_tran_hoan_vi = false;
            }
            tong_hang += matrix[i][j];
        }
        if (tong_hang != 1)
        {
            la_ma_tran_hoan_vi = false;
        }
    }

    if (la_ma_tran_hoan_vi)
    {
        for (int j = 0; j < n; j++)
        {
            int tong_cot = 0;
            for (int i = 0; i < n; i++)
            {
                tong_cot += matrix[i][j];
            }
            if (tong_cot != 1)
            {
                la_ma_tran_hoan_vi = false;
            }
        }
    }

    if (!la_ma_tran_hoan_vi)
    {
        cout << "khong phai ma tran hoan vi";
    }
    else
    {
        vector<int> s_phay(n);

        for (int j = 0; j < n; j++)
        { 
            int sum = 0;
            for (int i = 0; i < n; i++)
            { 
                sum += s[i] * matrix[i][j];
            }
            s_phay[j] = sum;
        }

        for (int i = 0; i < n; i++)
        {
            cout << s_phay[i] << (i == n - 1 ? "" : " ");
        }
    }

    return 0;
}