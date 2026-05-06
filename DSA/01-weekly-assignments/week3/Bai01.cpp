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
NODE *CreateNode(int x)
{
    NODE *p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}
void InsertHead(LIST &L, NODE *p)
{
    p->pNext = L.pHead;
    L.pHead = p;
}
void CreateEmptyList(LIST &L)
{
    L.pHead = NULL;
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
        InsertHead(L, CreateNode(x));
    }
    PrintList(L);
    return 0;
}
