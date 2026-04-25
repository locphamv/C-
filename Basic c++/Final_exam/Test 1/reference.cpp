#include <iostream>
using namespace std;

int func(int a, int &b)
{
    a += 10;
    b += 2;
    return a;
}
int main()
{
    int a = 3, b = 6;
    b = func(b, a);
    cout << a << " " << b;
}