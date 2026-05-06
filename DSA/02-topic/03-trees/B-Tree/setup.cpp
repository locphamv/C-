#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int keys[4];
    Node *child[5];
    int n;
    bool leaf;
    Node(bool isLeaf = true)
    {
        n = 0;
        leaf = isLeaf;
        for (int i = 0; i < 5; i++)
        {
            child[i] = NULL;
        }
    }
};

void printNode(Node *p)
{
    cout << "[";
    for (int i = 0; i < p->n; i++)
    {
        cout << p->keys[i] << " ";
    }
    cout << "]";
}

void traverse(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    for (int i = 0; i < root->n; i++)
    {
        if (!root->leaf)
        {
            traverse(root->child[i]);
        }
        cout << root->keys[i] << " ";
    }
    if (!root->leaf)
    {
        traverse(root->child[root->n]);
    }
}

int findPos(Node *p, int x)
{
    int i = 0;
    while (i < p->n && p->keys[i] < x)
    {
        i++;
    }
    return i;
}

void insertIntoLeaf(Node *p, int x)
{
    int i = p->n - 1;
    while (i >= 0 && p->keys[i] > x)
    {
        p->keys[i + 1] = p->keys[i];
        i--;
    }
    p->keys[i + 1] = x;
    p->n++;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = new Node;
    insertIntoLeaf(root, 10);
    insertIntoLeaf(root, 20);
    insertIntoLeaf(root, 40);
    insertIntoLeaf(root, 15);

    printNode(root);

    return 0;
}