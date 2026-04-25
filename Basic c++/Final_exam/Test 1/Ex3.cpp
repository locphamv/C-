#include <iostream>
using namespace std;

void run(char s[])
{
    int n = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        n++;
    }
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (isupper(s[i]))
        {
            dem++;
        }
    }
    if (dem == 0)
    {
        cout << -1;
        return;
    }
    cout << dem;
}

int main()
{
    char s[100];
    cin.getline(s, 100);
    run(s);
    return 0;
}