#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct List {
    Node *head;
    Node *tail;
};

void init(List &list) {
    list.head = nullptr;
    list.tail = nullptr;
}

Node *createNode(int value) {
    Node *p = new Node;
    p->data = value;
    p->next = nullptr;
    return p;
}

void addLast(List &list, int value) {
    Node *p = createNode(value);

    if (list.head == nullptr) {
        list.head = p;
        list.tail = p;
    } else {
        list.tail->next = p;
        list.tail = p;
    }
}

void printList(const List &list) {
    Node *p = list.head;

    while (p != nullptr) {
        cout << p->data;

        if (p->next != nullptr) {
            cout << ' ';
        }

        p = p->next;
    }

    cout << '\n';
}

void clearList(List &list) {
    while (list.head != nullptr) {
        Node *p = list.head;
        list.head = list.head->next;
        delete p;
    }

    list.tail = nullptr;
}

Node *reverseRecursive(Node *current) {
    if (current == nullptr || current->next == nullptr) {
        return current;
    }

    Node *newHead = reverseRecursive(current->next);

    current->next->next = current;
    current->next = nullptr;

    return newHead;
}
void reverseLinkedList(List &list) {
    if (list.head == nullptr || list.head->next == nullptr) {
        return;
    }

    Node *oldHead = list.head;

    list.head = reverseRecursive(list.head);
    list.tail = oldHead;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    List list;
    init(list);

    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        addLast(list, value);
    }
    int k;
    cin >> k;

    reverseLinkedList(list);
    Node *p = list.head;
    for (int i = 0; i < k - 1; i++) {
        p = p->next;
    }
    cout << p->data << "\n";

    printList(list);

    clearList(list);

    return 0;
}