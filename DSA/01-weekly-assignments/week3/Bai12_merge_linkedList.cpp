#include<bits/stdc++.h>
using namespace std;

struct NODE
{
    int info;
    NODE *pNext;
};

struct LIST
{
    NODE*pHead;
    NODE*pTail;
};

void CreateEmptyList(LIST &L) {
    L.pHead = NULL;
    L.pTail = NULL;
}

NODE* CreateNode(int x) {
    NODE* p = new NODE;
    if (p == NULL)
        exit(1);
    p->info = x;
    p->pNext = NULL;
    return p;
}

void InsertTail(LIST &L, NODE*p)
{
    if(L.pHead==NULL)
    {
        L.pHead=L.pTail=p;
    }
    else
    {
        L.pTail->pNext=p;
        L.pTail=p;
    }
}

void PrintList (LIST L)
{
    NODE*p=L.pHead;
    while(p)
    {
        cout<<p->info<<" ";
        p=p->pNext;
    }
}

void MergeList(LIST&L1, LIST&L2)
{
    L1.pTail->pNext=L2.pHead;
    L1.pTail=L2.pTail;
}

int main()
{
    LIST L1,L2;
    CreateEmptyList(L1);
    CreateEmptyList(L2);
    int n; cin >> n;
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        InsertTail(L1, CreateNode(x));
    }

    int k;
    cin>>k;
    for (int i = 0; i < k; i++){
        cin >> x;
        InsertTail(L2, CreateNode(x));
    }

    MergeList(L1, L2);
    PrintList(L1);
    cout<<"\n";
    PrintList(L2);
    return 0;
}