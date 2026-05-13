#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node
{
    int value;
    Node *left;
    Node *right;
    Node() : value(0), left(nullptr), right(nullptr) {};
};

Node *createNode(int data)
{
    Node *p = new Node;
    p->value = data;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

Node *InsertTree(Node *root, int data)
{
    if (root == nullptr)
    {
        return createNode(data);
    }
    if (data < root->value)
        root->left = InsertTree(root->left, data);
    else
        root->right = InsertTree(root->right, data);

    return root;
}

int levelCount(Node *root, int targetLevel)
{
    if (root == nullptr)
    {
        return 0;
    }
    queue<Node *> q;
    q.push(root);
    int level = 0;
    while (!q.empty())
    {
        int levelSize = q.size();
        if (level == targetLevel)
        {
            return levelSize;
        }
        for (int i = 0; i < levelSize; i++)
        {
            Node *p = q.front();
            q.pop();

            if (p->left != NULL)
            {
                q.push(p->left);
            }
            if (p->right != NULL)
            {
                q.push(p->right);
            }
        }
        level++;
    }
    return 0;
}

void levelTrans(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *p = q.front();
        cout << p->value << " ";
        q.pop();

        if (p->left != NULL)
        {
            q.push(p->left);
        }
        if (p->right != NULL)
        {
            q.push(p->right);
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    Node *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        root = InsertTree(root, tmp);
    }

    cout << levelCount(root, k);
}