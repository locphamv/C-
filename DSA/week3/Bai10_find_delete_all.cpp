
#include <bits/stdc++.h>
using namespace std;

struct NODE {
    int info;
    NODE* pNext;
};


struct LIST {
    NODE* pHead;
    NODE* pTail;
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

void PrintList(LIST L)
{
    NODE *p = L.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
}

void InsertTail(LIST &L, NODE* p) {
    if (L.pHead == NULL) {
        L.pTail = p;
        L.pHead = L.pTail;
    }
    else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void TimKiemVaXoa(LIST &, int);

bool TimKiem(LIST L, int k, NODE* &pTruoc)
{
    pTruoc=NULL;
    NODE*p=L.pHead;

    while(p!=NULL)
    {
        if(p->info==k)
        {
            return true;
        }
        pTruoc=p;
        p=p->pNext;
    }

    return false;
}

void DeleteNode(LIST &L, NODE*pTruoc)
{
    if(pTruoc==NULL)
    {
    NODE*tmp=L.pHead;
    L.pHead=L.pHead->pNext;
    delete tmp;
    tmp=NULL;

    if(L.pHead==NULL)
    {
        L.pTail=NULL;
    }
    return;
    }

    NODE *tmpp=pTruoc->pNext;
    pTruoc->pNext=pTruoc->pNext->pNext;
    delete tmpp;
    tmpp=NULL;

    if(pTruoc->pNext==NULL)
    {
        L.pTail=pTruoc;
    }
}

void TimKiemVaXoa(LIST & L, int k)
{
    if(L.pHead==NULL)
    {
        cout<<-1;
        return;
    }

    NODE*pTruoc;

    bool found=TimKiem(L,k,pTruoc);
    if(!found)
    {
        cout<<-1;
        return;
    }

    if(pTruoc==NULL && L.pHead->info!=k)
    {
        cout<<-1;
        return;
    }

    while(found)
    {
        DeleteNode(L,pTruoc);
        found=TimKiem(L,k,pTruoc);
    }
    PrintList(L);
}




int main()
{
    LIST L;
    CreateEmptyList(L);
    int n; cin >> n;
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        InsertTail(L, CreateNode(x));
    }
    int k; cin >> k;
    TimKiemVaXoa(L, k);
    return 0;
}