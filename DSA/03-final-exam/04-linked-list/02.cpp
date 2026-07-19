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

int countNodes(const List &list) {
    int count = 0;
    Node *p = list.head;

    while (p != nullptr) {
        ++count;
        p = p->next;
    }

    return count;
}

long long sumList(const List &list) {
    long long sum = 0;
    Node *p = list.head;

    while (p != nullptr) {
        sum += p->data;
        p = p->next;
    }

    return sum;
}

void clearList(List &list) {
    while (list.head != nullptr) {
        Node *p = list.head;
        list.head = list.head->next;
        delete p;
    }

    list.tail = nullptr;
}

void insertAfterFirst(List &list, int x, int y) {
    Node *p = list.head;

    while (p) {
        if (p->data == x) {
            Node *newNode = createNode(y);
            newNode->next = p->next;
            p->next = newNode;

            if (list.tail == p) {
                list.tail = newNode;
            }
            return;
        }
        p = p->next;
    }
    addLast(list, y);
}

void deleteAll(List &list, int x) {
    while (list.head != nullptr && list.head->data == x) {
        Node *tmp = list.head;
        list.head = list.head->next;
        delete tmp;
    }
    if (list.head == nullptr) {
        list.tail = nullptr;
        return;
    }
    Node *p = list.head;
    while (p->next != nullptr) {
        if (p->next->data == x) {
            Node *temp = p->next;
            p->next = temp->next;
            delete temp;
        } else {
            p = p->next;
        }
    }
    list.tail = p;
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

    int x, y;
    cin >> x >> y;
    insertAfterFirst(list, x, y);
    deleteAll(list, x);

    printList(list);

    clearList(list);

    return 0;
}