
#include <iostream>
#include <vector>
using namespace std;


// struct NODE
// {
//     int data;
//     NODE *pNext;
// };

// struct LIST
// {
//     NODE *pHead;
// };

// void CreateEmptyList(LIST &L)
// {
//     L.pHead=NULL;
// }

// NODE* CreateNode(int x)
// {
//     NODE *p= new NODE;
//     p->data=x;
//     p->pNext=NULL;
//     return p;
// }

// void  InsertTail(LIST &L, NODE *addNode)
// {
//     if(L.pHead==NULL)
//     {
//         L.pHead=addNode;
//         return;
//     }
//     NODE *p= L.pHead;
//     while(p->pNext!= NULL)
//     {
//         p=p->pNext;
//     }
//     p->pNext=addNode;
// }

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

void TimKiem(LIST, int);

void TimKiem(LIST L, int k)
{
    int count=0;
    int check=0;
    NODE *p=L.pHead;
    while(p!=NULL)
    {
        if(p->info==k)
        {
            cout<<count<<" ";
            check++;
        }
        
            p=p->pNext;
            count++;
        
    }
    if(check==0)
    {
        cout<<-1;
    }
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
    TimKiem(L, k);
   
    
    return 0;
}