#include <iostream>
#include <string>
using namespace std;

void traVeKetQua(string a, string b)
{
    if (a == "KEO" && b == "BAO" || a == "BUA" && b == "KEO" || a == "BAO" && b == "BUA")
    {
        cout << "A WON" << "(" << a << "-" << b << ")";
    }
    else if (a == "KEO" && b == "BUA" || a == "BUA" && b == "BAO" || a == "BAO" && b == "KEO")
    {
        cout << "B WON" << "(" << a << "-" << b << ")";
    }
    else
    {
        cout << "DRAW" << "(" << a << "-" << b << ")";
    }
}

int main()
{
    string n1, n2, n3, n4, n5, n6;
    cin >> n1 >> n2 >> n3 >> n4 >> n5 >> n6;
    string finalA, finalB;
    if (n5 == "PHAI")
    {
        finalA = n1;
    }
    else
    {
        finalA = n2;
    }
    if (n6 == "TRAI")
    {
        finalB = n4;
    }
    else
    {
        finalB = n3;
    }

    traVeKetQua(finalA, finalB);

    return 0;
}