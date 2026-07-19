#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
};

Node *createNode(int x) {
    Node *p = new Node;
    p->key = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

Node *InsertTree(Node *root, int x) {
    if (root == nullptr) {
        return createNode(x);
    }
    if (x < root->key) {
        root->left = InsertTree(root->left, x);
    } else {
        root->right = InsertTree(root->right, x);
    }
    return root;
}

void inOrder(Node *root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
}

void levelTrans(Node *root) {
    if (root == nullptr) {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *p = q.front();
        q.pop();
        cout << p->key << " ";
        if (p->left) {
            q.push(p->left);
        }
        if (p->right) {
            q.push(p->right);
        }
    }
}

int main() {
    int n;
    cin >> n;

    Node *root = nullptr;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        root = InsertTree(root, tmp);
    }
    inOrder(root);
    cout << endl;
    levelTrans(root);
}