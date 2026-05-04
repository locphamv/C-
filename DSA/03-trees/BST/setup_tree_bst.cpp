#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int x)
{
    Node *p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void Preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void LevelOrder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        cout << p->data << " ";

        if (p->left != NULL)
            q.push(p->left);
        if (p->right != NULL)
            q.push(p->right);
    }
}
void Inorder(Node *root)
{
    if (root == NULL)
        return;

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Postorder(Node *root)
{
    if (root == NULL)
        return;

    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

Node *Search(Node *root, int x)
{
    if (root == NULL || root->data == x)
    {
        return root;
    }
    if (root->data > x)
    {
        return Search(root->left, x);
    }
    else
    {
        return Search(root->right, x);
    }
}

Node *Insert(Node *root, int x)
{
    if (root == NULL)
    {
        return createNode(x);
    }
    if (x < root->data)
    {
        root->left = Insert(root->left, x);
    }
    else if (x > root->data)
    {
        root->right = Insert(root->right, x);
    }
    return root;
}

int CountNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + CountNodes(root->left) + CountNodes(root->right);
}

int CountLeaf(Node *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return CountLeaf(root->left) + CountLeaf(root->right);
}

int Height(Node *root)
{
    if (root == NULL)
        return -1;

    return 1 + max(Height(root->left), Height(root->right));
}

Node *FindMin(Node *root)
{
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *DeleteNode(Node *root, int x)
{
    if (root == NULL)
        return NULL;

    if (x < root->data)
    {
        root->left = DeleteNode(root->left, x);
    }
    else if (x > root->data)
    {
        root->right = DeleteNode(root->right, x);
    }
    else
    {
        // Case 1: no child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // Case 2: only right child
        else if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // Case 2: only left child
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: two children
        else
        {
            Node *temp = FindMin(root->right); // inorder successor
            root->data = temp->data;
            root->right = DeleteNode(root->right, temp->data);
        }
    }

    return root;
}
int main()
{
    Node *root = NULL;
    root = Insert(root, 20);
    root = Insert(root, 17);
    root = Insert(root, 30);
    root = Insert(root, 49);
    root = Insert(root, 15);
    root = Insert(root, 28);
    root = Insert(root, 33);
    root = Insert(root, 10);
    root = DeleteNode(root, 30);
    Inorder(root);
    cout << "\n";

    return 0;
}