#include <iostream>
using namespace std;

int main()
{
    long long n;
    long long max, min;
    bool foundFirst = true;
    while (true)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }
        if (foundFirst)
        {
            max = n;
            min = n;
            foundFirst = false;
        }
        else
        {
            if (n > max)
                max = n;
            if (n < min)
                min = n;
        }
    }
    cout << max << endl
         << min;
    return 0;
}