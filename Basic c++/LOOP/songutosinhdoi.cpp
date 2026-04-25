#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    if (n != 2 && n % 2 == 0)
    {
        return false;
    }
    for (int i = 3; i < n; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int x = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        if (isPrime(i) && isPrime(i + 2))
        {
            if (i + 2 <= n)
            {
                cout << i << " " << i + 2 << endl;
                x++;
            }
        }
    }
    cout << "Tong: " << x << " cap so sinh doi < " << n;
}