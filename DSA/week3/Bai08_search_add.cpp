
#include <iostream>
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




NODE * TimKiem(LIST L, int k)
{
    NODE*p=L.pHead;
    while(p)
    {
        if(p->info==k)
        {
            return p;
        }
        p=p->pNext;
    }
    return p;
}

void InsertNode(LIST&L,NODE*tmp)
{
    NODE*p=L.pHead;
    while(p->pNext)
    {
        p=p->pNext;
    }
    p->pNext=tmp;
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

void TimKiemVaThem(LIST & L, int k)
{
    NODE*tmp= new NODE;
    tmp->info=1999;
    tmp->pNext=NULL;
    NODE*p=TimKiem(L,k);
    if(p==NULL)
    {
        InsertNode(L,tmp);
    }
    else
    {
        tmp->pNext=p->pNext;
        p->pNext=tmp;
    }
    PrintList(L);
}

NODE* TimKiem(LIST, int);
void InsertNode(LIST &, NODE*);
void TimKiemVaThem(LIST &, int);

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
    TimKiemVaThem(L, k);
    return 0;
}
