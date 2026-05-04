#include <bits/stdc++.h>

using namespace std;

class Node
{
  public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
  public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    /*
    class Node {
        public:
            int data;
            Node *left;
            Node *right;
            Node(int d) {
                data = d;
                left = NULL;
                right = NULL;
            }
    };

    */

    void topView(Node *root)
    {
        queue<pair<int, Node *>> q;
        q.push({0, root});
        map<int, Node *> ans;

        while (!q.empty())
        {
            auto it = q.front();
            if (it.second != NULL)
            {
                ans.insert(it);
                q.push({it.first + 1, it.second->right});
                q.push({it.first - 1, it.second->left});
            }
            q.pop();
        }

        for (auto it : ans)
        {
            cout << it.second->data << " ";
        }
    }
};

int main()
{

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.topView(root);
    return 0;
}
