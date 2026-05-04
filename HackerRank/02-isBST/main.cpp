#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node()
    {
        this->data = -1;
        this->left = NULL;
        this->right = NULL;
    }
};

class Tree
{

  public:
    std::vector<int> values;

    int count;

    Tree()
    {
        this->count = 0;
    }

    bool checkBST(Node *root)
    {
        vector<int> inOrderList;
        getInOrder(root, inOrderList);
        for (int i = 1; i < inOrderList.size(); i++)
        {
            if (inOrderList[i] <= inOrderList[i - 1])
                return false;
        }
        return true;
    }

    void getInOrder(Node *root, vector<int> &inOrderList)
    {
        if (root == NULL)
        {
            return;
        }
        getInOrder(root->left, inOrderList);
        inOrderList.push_back(root->data);
        getInOrder(root->right, inOrderList);
    }
    void inOrder(Node *root, int levels)
    {

        if (root != NULL)
        {

            if (levels > 0)
            {

                root->left = new Node();
                inOrder(root->left, levels - 1);
            }

            root->data = values.at(count);
            count++;

            if (levels > 0)
            {

                root->right = new Node();
                inOrder(root->right, levels - 1);
            }
        }
    }
};

int main(int argc, char *argv[])
{
    int height;
    cin >> height;

    Tree *tree = new Tree();
    int value;
    while (cin >> value)
    {
        tree->values.push_back(value);
    }

    Node *root = new Node();
    tree->inOrder(root, height);

    if (tree->checkBST(root) == true)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}
