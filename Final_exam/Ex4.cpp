#include <iostream>
#include <string>

using namespace std;

string DoiSangLaMa(int n)
{
    if (n <= 0)
        return "";

    int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string ketqua = "";
    for (int i = 0; i < 13; i++)
    {
        while (n >= val[i])
        {
            ketqua += sym[i];
            n -= val[i];
        }
    }
    return ketqua;
}

int main()
{
    int n;
    cin >> n;

    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << DoiSangLaMa(a[i]) << endl;
    }
    delete[] a;
    return 0;
}