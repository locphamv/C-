#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> nums;
    stack<int> mins;
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++)
    {
        string a;
        cin>>a;
        if(a=="push")
        {
            int x;
            cin>>x;

            nums.push(x);
        
            if(mins.empty())
            {
                mins.push(x);
            }
            else if(x <=mins.top())
            {
                mins.push(x);
            }    
            continue;
        }
        if(a=="pop")
        {
            if(!nums.empty())
            {
            if(nums.top()==mins.top())
            {
                mins.pop();
            }
                nums.pop();
            }
            continue;
        }
        if(a == "top" && !nums.empty())
        {
            cout<<nums.top()<<"\n";
            continue;
        }
        if(!mins.empty() && a == "getMin")
        {
            cout<<mins.top()<<"\n";
        }
    }
}