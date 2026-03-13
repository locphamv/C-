#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> arr, int n, int k, int &dem)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        dem++;
        int mid = left + (right - left) / 2;
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid] < k)
        {
            left = mid + 1;
        }
        else if (arr[mid] > k)
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n, k;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> k;
    int dem = 0;
    int tmp = binary_search(arr, n, k, dem);
    cout << tmp << endl;
    if (tmp != -1)
    {
        cout << dem;
    }
}