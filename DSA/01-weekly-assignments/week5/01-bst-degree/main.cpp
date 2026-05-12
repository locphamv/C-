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

void createList(Node *root, vector<Node *> &v)
{
    if (root == nullptr)
    {
        return;
    }
    createList(root->left, v);
    v.push_back(root);
    createList(root->right, v);
}

int degreeMax(Node *root, vector<Node *> v)
{

    int maxD = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (degree(v[i]) > maxD)
        {
            maxD = degree(v[i]);
        }
    }
    return maxD;
}

// int height(Node *root)
// {
//     if (root == nullptr)
//     {
//         return -1;
//     }
//     return 1 + max(height(root->left), height(root->right));
// }

// void inorderTranversal(Node *root)
// {
//     if (root == nullptr)
//     {
//         return;
//     }
//     inorderTranversal(root->left);
//     cout << root->value << " ";
//     inorderTranversal(root->right);
// }

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

    vector<Node *> v;
    createList(root, v);
    cout << degreeMax(root, v);
}