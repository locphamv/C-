#include <bits/stdc++.h>
using namespace std;

enum Color
{
    RED,
    BLACK
};

struct Node
{
    int data;
    Color color;
    Node *left;
    Node *right;
    Node *parent;

    Node(int val)
    {
        data = val;
        color = RED; // node mới chèn thường tô đỏ
        left = right = parent = NULL;
    }
};

class RedBlackTree
{
  private:
    Node *root;

    void rotateLeft(Node *x)
    {
        Node *y = x->right;
        x->right = y->left;

        if (y->left != NULL)
            y->left->parent = x;

        y->parent = x->parent;

        if (x->parent == NULL)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node *y)
    {
        Node *x = y->left;
        y->left = x->right;

        if (x->right != NULL)
            x->right->parent = y;

        x->parent = y->parent;

        if (y->parent == NULL)
            root = x;
        else if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;

        x->right = y;
        y->parent = x;
    }
    void bstInsert(Node *z)
    {
        Node *y = NULL;
        Node *x = root;

        while (x != NULL)
        {
            y = x;
            if (z->data < x->data)
                x = x->left;
            else
                x = x->right;
        }

        z->parent = y;

        if (y == NULL)
            root = z;
        else if (z->data < y->data)
            y->left = z;
        else
            y->right = z;
    }

    void fixInsert(Node *z)
    {
        while (z != root && z->parent->color == RED)
        {
            Node *p = z->parent;
            Node *g = p->parent;

            if (p == g->left)
            {
                Node *u = g->right; // uncle

                // Case 1: chú đỏ -> đổi màu
                if (u != NULL && u->color == RED)
                {
                    p->color = BLACK;
                    u->color = BLACK;
                    g->color = RED;
                    z = g;
                }
                else
                {
                    // Case 2: LR
                    if (z == p->right)
                    {
                        z = p;
                        rotateLeft(z);
                        p = z->parent;
                        g = p->parent;
                    }

                    // Case 3: LL
                    p->color = BLACK;
                    g->color = RED;
                    rotateRight(g);
                }
            }
            else
            {
                Node *u = g->left; // uncle

                // Case 1 đối xứng: chú đỏ
                if (u != NULL && u->color == RED)
                {
                    p->color = BLACK;
                    u->color = BLACK;
                    g->color = RED;
                    z = g;
                }
                else
                {
                    // Case 2 đối xứng: RL
                    if (z == p->left)
                    {
                        z = p;
                        rotateRight(z);
                        p = z->parent;
                        g = p->parent;
                    }

                    // Case 3 đối xứng: RR
                    p->color = BLACK;
                    g->color = RED;
                    rotateLeft(g);
                }
            }
        }

        root->color = BLACK;
    }

  public:
    RedBlackTree() { root = NULL; }

    void insert(int val)
    {
        Node *z = new Node(val);
        bstInsert(z);
        fixInsert(z);
    }
    void inorder(Node *node)
    {
        if (node == NULL)
            return;

        inorder(node->left);
        cout << node->data << "(" << (node->color == RED ? "R" : "B") << ") ";
        inorder(node->right);
    }

    void inorder()
    {
        inorder(root);
        cout << '\n';
    }
};
int main()
{
    RedBlackTree t;

    t.insert(10);
    t.insert(20);
    t.insert(30);
    t.insert(15);
    t.insert(25);
    t.insert(5);

    t.inorder();

    return 0;
}