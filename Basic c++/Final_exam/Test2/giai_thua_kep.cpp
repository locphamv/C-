#include <iostream>
using namespace std;

long long sum(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * sum(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << sum(n);
}