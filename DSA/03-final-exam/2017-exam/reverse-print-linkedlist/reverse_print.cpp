#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *Next;
};

struct List
{
    Node *Head;
    Node *Tail;
};

void Init(List &ls)
{
    ls.Head = NULL;
    ls.Tail = NULL;
}

Node *CreateNode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->Next = NULL;
    return p;
}

void AddTail(List &ls, int x)
{
    Node *p = CreateNode(x);

    if (ls.Head == NULL)
    {
        ls.Head = p;
        ls.Tail = p;
    }
    else
    {
        ls.Tail->Next = p;
        ls.Tail = p;
    }
}

// Recursive function to print nodes in reverse order.
// It first moves to the end of the list, then prints while returning.
void RPrintNode(Node *p)
{
    if (p == NULL)
        return;

    RPrintNode(p->Next);
    cout << p->info << " ";
}

// Wrapper function: starts reverse printing from the head of the list.
void RPrint(List ls)
{
    RPrintNode(ls.Head);
}


void Print(List ls)
{
    Node *p = ls.Head;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->Next;
    }
}

void DeleteList(List &ls)
{
    Node *p = ls.Head;
    while (p != NULL)
    {
        Node *temp = p;
        p = p->Next;
        delete temp;
    }

    ls.Head = NULL;
    ls.Tail = NULL;
}

int main()
{
    List ls;
    Init(ls);

    AddTail(ls, 1);
    AddTail(ls, 2);
    AddTail(ls, 3);
    AddTail(ls, 4);
    AddTail(ls, 5);

    cout << "Danh sach ban dau: ";
    Print(ls);

    cout << "\nDanh sach in nguoc: ";
    RPrint(ls);

    DeleteList(ls);

    return 0;
}
