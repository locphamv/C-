
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main() {
    int n, q, x;
    cin >> n >> q;

    unordered_set<int> s;

    for (int i = 0; i < n; i++) {
        cin >> x;
        s.insert(x);   
    }

    for (int i = 0; i < q; i++) {
        cin >> x;
        if (s.find(x) != s.end()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}











// #include <bits/stdc++.h>
// using namespace std;

// struct NODE
// {
//     int data;
//     NODE*pNext;
// };

// struct LIST
// {
//     NODE*pHead;
//     NODE*pTail;
// };

// void initList (LIST &L)
// {
//     L.pHead=NULL;
//     L.pTail=NULL;
// }

// NODE* creatNode (int x)
// {
//     NODE*p=new NODE;
//     p->data=x;
//     p->pNext=NULL;
//     return p;
// }

// void insertTail(LIST &L, NODE* added)
// {
//     if(L.pHead==NULL)
//     {
//         L.pHead=added;
//         L.pTail=added;
//     }
//     else
//     {
//        L.pTail->pNext=added;
//        L.pTail=added;
//     }
// }

// void display(LIST L)
// {
//     NODE*p=L.pHead;
//     while(p)
//     {
//         cout<<p->data<<" ";
//         p=p->pNext;
//     }
// }

// void check(LIST L, int x)
// {
//     NODE*p=L.pHead;
//     while(p)
//     {
//         if(p->data==x)
//         {
//             cout<<"YES\n";
//             return;
//         }
//         p=p->pNext;
//     }
//     cout<<"NO\n";
// }

// int main()
// {
//     LIST L;
//     initList(L);
//     int n,q;
//     cin>>n>>q;
//     int x;
//     for(int i=0; i<n; i++)
//     {
//         cin>>x;
//         insertTail(L,creatNode(x));
//     }


//     for(int j=0; j<q; j++)
//     {
//         cin>>x;
//         check(L,x);
//     }

// }
