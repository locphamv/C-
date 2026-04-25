#include <iostream>
using namespace std;

int N, M;
long long K;

long long gia[12];
long long tang[12][12];

long long dapAn = 1000000000000000000LL;

bool duKienThuc(long long hieuBiet[])
{
    for (int j = 0; j < M; j++)
    {
        if (hieuBiet[j] < K)
            return false;
    }
    return true;
}

void thu(int i, long long tongTien, long long hieuBiet[])
{

    if (tongTien >= dapAn)
        return;

    if (i == N)
    {
        if (duKienThuc(hieuBiet))
        {
            if (tongTien < dapAn)
                dapAn = tongTien;
        }
        return;
    }

    thu(i + 1, tongTien, hieuBiet);

    long long hieuBiet2[12];
    for (int j = 0; j < M; j++)
        hieuBiet2[j] = hieuBiet[j];
    for (int j = 0; j < M; j++)
        hieuBiet2[j] += tang[i][j];

    thu(i + 1, tongTien + gia[i], hieuBiet2);
}

int main()
{
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> gia[i];
        for (int j = 0; j < M; j++)
            cin >> tang[i][j];
    }

    long long hieuBietBanDau[12];
    for (int j = 0; j < M; j++)
        hieuBietBanDau[j] = 0;

    thu(0, 0, hieuBietBanDau);

    if (dapAn == 1000000000000000000LL)
        cout << -1;
    else
        cout << dapAn;

    return 0;
}
