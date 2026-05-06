#include <bits/stdc++.h>
using namespace std;

const int T = 2;

struct Node
{
    int keys[2 * T - 1];
    Node *child[2 * T];
    int n;
    bool leaf;

    Node(bool isLeaf = true)
    {
        leaf = isLeaf;
        n = 0;
        for (int i = 0; i < 2 * T; i++)
        {
            child[i] = NULL;
        }
    }
};

void traverse(Node *root)
{
    if (root == NULL)
        return;

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

void printNode(Node *p)
{
    cout << "[ ";
    for (int i = 0; i < p->n; i++)
    {
        cout << p->keys[i] << " ";
    }
    cout << "]";
}

void splitChild(Node *parent, int i)
{
    // 1. Lấy node con y đang đầy
    // 2. Tách y thành hai node: y và z
    // 3. Đẩy key giữa của y lên parent

    Node *y = parent->child[i];
    Node *z = new Node(y->leaf);

    z->n = T - 1;

    for (int j = 0; j < T - 1; j++)
    {
        z->keys[j] = y->keys[j + T];
    }

    if (!y->leaf)
    {
        for (int j = 0; j < T; j++)
        {
            z->child[j] = y->child[j + T];
        }
    }

    int middleKey = y->keys[T - 1];
    y->n = T - 1;

    for (int j = parent->n; j >= i + 1; j--)
    {
        parent->child[j + 1] = parent->child[j];
    }
    parent->child[i + 1] = z;

    for (int j = parent->n - 1; j >= i; j--)
    {
        parent->keys[j + 1] = parent->keys[j];
    }
    parent->keys[i] = middleKey;

    parent->n++;
}


void insertNonFull(Node *x, int k)
{
    int i = x->n - 1;

    if (x->leaf)
    {
        while (i >= 0 && x->keys[i] > k)
        {
            x->keys[i + 1] = x->keys[i];
            i--;
        }

        x->keys[i + 1] = k;
        x->n++;
    }
    else
    {
        while (i >= 0 && x->keys[i] > k)
        {
            i--;
        }
        i++;

        if (x->child[i]->n == 2 * T - 1)
        {
            splitChild(x, i);

            if (k > x->keys[i])
            {
                i++;
            }
        }

        insertNonFull(x->child[i], k);
    }
}

Node *insert(Node *root, int k)
{
    if (root == NULL)
    {
        root = new Node(true);
        root->keys[0] = k;
        root->n = 1;
        return root;
    }

    if (root->n == 2 * T - 1)
    {
        Node *s = new Node(false);
        s->child[0] = root;

        splitChild(s, 0);

        int i = 0;
        if (k > s->keys[0])
        {
            i = 1;
        }

        insertNonFull(s->child[i], k);
        return s;
    }
    else
    {
        insertNonFull(root, k);
        return root;
    }
}

int main()
{
    Node *root = NULL;

    vector<int> a = {10, 20, 30, 110, 50, 60, 70, 80, 90, 100};

    for (int x : a)
    {
        root = insert(root, x);
    }

    cout << "Traverse: ";
    traverse(root);
    cout << "\n";

    return 0;
}