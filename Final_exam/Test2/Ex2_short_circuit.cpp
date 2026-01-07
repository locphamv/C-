#include <iostream>
using namespace std;

int main()
{
    // int a = 5;
    // cout << (++a) + (a++);
    int a = 5;
    int sum = ((++a), (a++)); // tính ++a trước rồi a++ sau, sum sẽ nhận giá trị của (a++)

    cout << sum << " " << a;
}