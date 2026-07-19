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
    Node *node = new Node;
    node->data = value;
    node->next = nullptr;
    return node;
}

void addLast(List &list, int value) {
    Node *node = createNode(value);

    if (list.head == nullptr) {
        list.head = list.tail = node;
    } else {
        list.tail->next = node;
        list.tail = node;
    }
}

Node *findKthFromEnd(const List &list, int k) {
    if (k <= 0) {
        return nullptr;
    }

    Node *slow = list.head;
    Node *fast = list.head;

    // Cho fast đi trước k bước
    for (int i = 0; i < k; i++) {
        if (fast == nullptr) {
            return nullptr;
        }

        fast = fast->next;
    }

    // Cho hai con trỏ cùng đi
    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

void reverseLinkedList(List &list) {
    Node *previous = nullptr;
    Node *current = list.head;

    // Head cũ sẽ trở thành tail mới
    list.tail = list.head;

    while (current != nullptr) {
        Node *nextNode = current->next;

        current->next = previous;
        previous = current;
        current = nextNode;
    }

    list.head = previous;
}

void printList(const List &list) {
    Node *current = list.head;

    while (current != nullptr) {
        cout << current->data;

        if (current->next != nullptr) {
            cout << ' ';
        }

        current = current->next;
    }

    cout << '\n';
}

void clearList(List &list) {
    while (list.head != nullptr) {
        Node *nodeToDelete = list.head;
        list.head = list.head->next;
        delete nodeToDelete;
    }

    list.tail = nullptr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    List list;
    init(list);

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        addLast(list, value);
    }

    int k;
    cin >> k;

    Node *kthNode = findKthFromEnd(list, k);

    if (kthNode == nullptr) {
        cout << -1 << '\n';
    } else {
        cout << kthNode->data << '\n';
    }

    reverseLinkedList(list);
    printList(list);

    clearList(list);

    return 0;
}