#include <iostream>
using namespace std;

int main()
{
    int x = 20;
    cout << &x << endl;
    int &y = x;
    cout << &x << endl;
    cout << &y << endl;
    cout << ++x + 5 << endl;
    y = x + y;
    x = 30;
    cout << "x=" << x << "y=" << y;
    return 0;
}
