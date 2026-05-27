#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node
{
    int val;
    Node *next;
};

struct List
{
    Node *head;
    Node *tail;
};

Node *creatNode(int data)
{
    Node *p = new Node;
    p->val = data;
    p->next = nullptr;
    return p;
}

void CreateList(List &l)
{
    l.head = l.tail = nullptr;
}

struct HashTable
{
    int M;
    int n;
    List *table;
    HashTable(int m)
    {
        M = m;
        n = 0;
        table = new List[m];

        for (int i = 0; i < m; i++)
            CreateList(table[i]);
    }
};
void DeleteList(List &l)
{
    while (l.head)
    {
        Node *p = l.head;
        l.head = l.head->next;
        delete p;
    }

    l.tail = nullptr;
}

void DeleteHashTable(HashTable &ht)
{
    for (int i = 0; i < ht.M; i++)
        DeleteList(ht.table[i]);

    delete[] ht.table;
    ht.table = nullptr;
    ht.M = 0;
    ht.n = 0;
}
void addTail(List &l, int data)
{
    Node *p = creatNode(data);
    if (l.head == nullptr)
    {
        l.head = l.tail = p;
    }
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}

int Hash(HashTable ht, int data)
{
    return data % ht.M;
}

void PrintHashtable(HashTable ht)
{
    for (int i = 0; i < ht.M; i++)
    {
        Node *p = ht.table[i].head;
        while (p)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << '\n';
    }
}

int insert(HashTable &ht, int data, double load)
{
    double kq = (double)(ht.n + 1) / ht.M;

    if (kq > load)
        return 0;

    int index = Hash(ht, data);
    addTail(ht.table[index], data);
    ht.n++;

    return 1;
}

void search(HashTable ht, int data)
{
    int index = Hash(ht, data);
    Node *p = ht.table[index].head;
    int count = 0;
    while (p)
    {
        count++;
        if (p->val == data)
        {
            cout << count << endl;
            return;
        }
        p = p->next;
    }
    cout << "KHONG" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    double load;
    cin >> m >> load >> n;

    HashTable ht(m);
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        insert(ht, tmp, load);
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int val;
        cin >> val;
        search(ht, val);
    }
    DeleteHashTable(ht);
}