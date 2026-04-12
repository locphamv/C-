
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

void InsertTail(LIST &L, NODE* p) 
{
    if (L.pHead == NULL)
    {
        L.pTail = p;
        L.pHead = L.pTail;
    }
    else 
    {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void PrintList(LIST L)
{
    if(L.pHead==NULL)
    {
        return;
    }
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
    NODE*tmp=NULL;
    while(p)
    {
        if(p->info==k)
        {
            return tmp;
        }
        tmp=p;
        p=p->pNext;
    }
    return L.pTail;
}
void DeleteNode(LIST &L, NODE* nodeTruoc)
{
  
}
void TimKiemVaXoa(LIST &L, int k)
{
    if(L.pHead==NULL)               //danh sach rong
    {                       
            cout<<-1;
            return;
    }

    NODE*p=TimKiem(L,k);
    
    if(p==NULL) //neu k o node dau tien
    {
        NODE*tmp=L.pHead;
        L.pHead=L.pHead->pNext;
        delete tmp;             //xoa node dau tien
        tmp=NULL;

        if(L.pHead==NULL)
        {
            L.pTail=NULL;
        }                           
        PrintList(L);
        return;
    }

    if(p->pNext==NULL) //neu ko tim thay k
    {
        cout<<-1; 
        return;
    }
    if(p->pNext==L.pTail) //neu k nam o node cuoi
    {
        L.pTail=p;
    }
    NODE*tmpp=p->pNext;
    p->pNext=p->pNext->pNext;
    delete tmpp;
    tmpp=NULL;
    PrintList(L);
}



NODE* TimKiem(LIST, int);
void DeleteNode(LIST &, NODE*);
void TimKiemVaXoa(LIST &, int);


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
