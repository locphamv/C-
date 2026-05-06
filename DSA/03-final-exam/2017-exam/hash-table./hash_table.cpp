#include <iostream>
using namespace std;

const int M = 11;

struct Node
{
    int key;
    Node *next;
};

struct List
{
    Node *head;
    Node *tail;
};

struct HashTable
{
    List bucket[M];
};

void InitList(List &l)
{
    l.head = NULL;
    l.tail = NULL;
}

void InitHashTable(HashTable &ht)
{
    for (int i = 0; i < M; i++)
    {
        InitList(ht.bucket[i]);
    }
}

int Hash(int key)
{
    return (2 * key + 5) % M;
}

Node *CreateNode(int key)
{
    Node *p = new Node;
    p->key = key;
    p->next = NULL;
    return p;
}

void AddTail(List &l, int key)
{
    Node *p = CreateNode(key);

    if (l.head == NULL)
    {
        l.head = p;
        l.tail = p;
    }
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}

void Insert(HashTable &ht, int key)
{
    int index = Hash(key);
    AddTail(ht.bucket[index], key);
}

Node *Search(HashTable ht, int key)
{
    int index = Hash(key);

    Node *p = ht.bucket[index].head;

    while (p != NULL)
    {
        if (p->key == key)
            return p;

        p = p->next;
    }

    return NULL;
}

void PrintHashTable(HashTable ht)
{
    for (int i = 0; i < M; i++)
    {
        cout << i << ": ";

        Node *p = ht.bucket[i].head;

        while (p != NULL)
        {
            cout << p->key << " -> ";
            p = p->next;
        }

        cout << "NULL" << endl;
    }
}

void DeleteList(List &l)
{
    Node *p = l.head;

    while (p != NULL)
    {
        Node *temp = p;
        p = p->next;
        delete temp;
    }

    l.head = NULL;
    l.tail = NULL;
}

void DeleteHashTable(HashTable &ht)
{
    for (int i = 0; i < M; i++)
    {
        DeleteList(ht.bucket[i]);
    }
}

int main()
{
    HashTable ht;
    InitHashTable(ht);

    int K[] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5};
    int n = sizeof(K) / sizeof(K[0]);

    for (int i = 0; i < n; i++)
    {
        Insert(ht, K[i]);
    }

    cout << "Bang bam sau khi them cac key:" << endl;
    PrintHashTable(ht);

    int x;
    cout << "\nNhap key can tim: ";
    cin >> x;

    Node *result = Search(ht, x);

    if (result != NULL)
        cout << "Tim thay " << x << endl;
    else
        cout << "Khong tim thay " << x << endl;

    DeleteHashTable(ht);

    return 0;
}