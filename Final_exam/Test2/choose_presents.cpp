#include <iostream>
using namespace std;

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
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    long long total_ways = (long long)n * (n - 1) * (n - 2) / 6;
    long long invalid_ways = 0;

    int i = 0;
    while (i < n)
    {
        int count = 1;
        int j = i + 1;
        while (j < n && a[j] == a[i])
        {
            count++;
            j++;
        }
        if (count >= 2)
        {
            invalid_ways += (long long)count * (count - 1) / 2 * (n - count);
            if (count >= 3)
            {
                invalid_ways += (long long)count * (count - 1) * (count - 2) / 6;
            }
        }
        i = j;
    }

    cout << total_ways - invalid_ways;
    delete[] a;
    return 0;
}