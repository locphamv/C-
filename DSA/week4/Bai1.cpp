#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>stock(n);
    for(int i=0; i<n; i++)
    {
        cin>>stock[i];
    }
    int dem=1;
    for(int i=0; i<n; i++)
    {
        int x=stock[i];
        dem=1;
        for(int j=0; j<i; j++)
        {
            if(x>stock[j])
            {
                dem++;
            }
            else
            {
                dem=1;
            }
        }
        cout<<dem<<" ";
    }
}