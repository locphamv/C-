#include <iostream>
using namespace std;

int main()
{
    long long n, k, p, q;

    cin >> n >> k >> p >> q;

    long long aliceIdx = (p - 1) * 2 + q;

    long long bobBack = aliceIdx - k;
    long long bobFwd = aliceIdx + k;

    long long chosenIdx = -1;

    long long rowBack = -1, distBack = -1;
    long long rowFwd = -1, distFwd = -1;

    bool validBack = (bobBack >= 1);
    if (validBack)
    {
        rowBack = (bobBack + 1) / 2;
        distBack = abs(p - rowBack);
    }

    bool validFwd = (bobFwd <= n);
    if (validFwd)
    {
        rowFwd = (bobFwd + 1) / 2;
        distFwd = abs(rowFwd - p);
    }

    if (validBack && validFwd)
    {

        if (distBack <= distFwd)
        {

            chosenIdx = bobBack;
        }
        else
        {

            chosenIdx = bobFwd;
        }
    }
    else if (validBack)
    {

        chosenIdx = bobBack;
    }
    else if (validFwd)
    {

        chosenIdx = bobFwd;
    }

    if (chosenIdx == -1)
    {
        cout << -1;
    }
    else
    {

        long long u = (chosenIdx + 1) / 2;
        long long v = (chosenIdx % 2 == 0) ? 2 : 1;
        cout << u << " " << v;
    }

    return 0;
}
