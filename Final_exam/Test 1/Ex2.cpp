#include <iostream>
using namespace std;
int main()
{
    int x = 12, y = 24;
    cout << (x == y / 2 ? -x : y - x) << ",";
    cout << (x < y < 2) << ",";
    cout << (!2 && !(x > y));
}