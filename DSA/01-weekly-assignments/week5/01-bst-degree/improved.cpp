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

int degree(Node *p)
{
    if (p->left == nullptr && p->right == nullptr)
    {
        return 0;
    }
    if (p->left == nullptr || p->right == nullptr)
    {
        return 1;
    }
    else
        return 2;
}

int degreeMax(Node *root)
{
    if (root == nullptr)
        return 0;

    return max({degree(root), degreeMax(root->left), degreeMax(root->right)});
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Node *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        root = InsertTree(root, tmp);
    }

    cout << degreeMax(root);
}