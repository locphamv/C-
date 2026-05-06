
#include <iostream>
using namespace std;

struct NODE
{
    int info;
    NODE *pNext;
};

struct LIST
{
    NODE *pHead;
};
void CreateEmptyList(LIST &L)
{
    L.pHead = NULL;
}
NODE *CreateNode(int x)
{
    NODE *p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}

void InsertTail(LIST &L, NODE *moi)
{
    if (L.pHead == NULL)
    {
        L.pHead = moi;
        return;
    }

    NODE *p = L.pHead;
    while (p->pNext != NULL)
    {
        p = p->pNext;
    }

    p->pNext = moi;
}

void DeleteTail(LIST &L)
{
    if (L.pHead == NULL)
    {
        return;
    }
    if (L.pHead->pNext == NULL)
    {
        delete L.pHead;
        L.pHead = NULL;
        return;
    }
    else
    {
        NODE *p = L.pHead;
        while (p->pNext->pNext != NULL)
        {
            p = p->pNext;
        }
        delete p->pNext;
        p->pNext = NULL;
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
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        InsertTail(L, CreateNode(x));
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
        DeleteTail(L);
    PrintList(L);
    return 0;
}
