#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i * i <= n; i++)
    {
        long long square = i * i;
        if (n % square == 0)
        {
            sum += square;
        }
    }

    cout << sum;
}
