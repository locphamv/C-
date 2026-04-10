
#include <iostream>
using namespace std;


struct NODE
{
    int data;
    NODE*pNext;
};

struct LIST
{
    NODE *pHead;
};

void CreateEmptyList(LIST &L)
{
    L.pHead=NULL;
}

NODE* CreateNode(int x)
{
    NODE*p= new NODE;
    p->data=x;
    p->pNext=NULL;
    return p;
}

void InsertTail(LIST &L, NODE *addNode)
{
    if(L.pHead==NULL)
    {
        L.pHead=addNode;
    }
    else
    {
        NODE *p= L.pHead;
        while(p->pNext!=NULL)
        {
            p=p->pNext;
        }
        p->pNext=addNode;
    }
}


int TimKiem(LIST L, int k)
{

    NODE *p=L.pHead;
    int count =0;
    while(p!=NULL)
    {
        if(p->data==k)
        {
             return count;
        }
        p=p->pNext;
        count++;
    }

    return -1;
}


int TimKiem(LIST, int);


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
    cout << TimKiem(L, k);
    return 0;
}
