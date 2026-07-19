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

void updateTail(List &list) {
    list.tail = list.head;

    if (list.tail == nullptr) {
        return;
    }

    while (list.tail->next != nullptr) {
        list.tail = list.tail->next;
    }
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

void insertionSorted(Node *sortedHead, Node *node) {
    if (sortedHead == nullptr || node->data < sortedHead->data) {
        node->next = sortedHead;
        sortedHead = node;
        return;
    }
    Node *current = sortedHead;
    sortedHead = node;
    return;
}

Node *current = sortedHead;

while (current->next != nullptr && current->next->data <= node->data) {
    current = current->next;
}

node->next = current->next;
current->next = node;
}

void insertionSort(List &list) {
    Node *sortedHead = nullptr;
    Node *current = list.head;

    while (current != nullptr) {
        // Lưu phần chưa xử lý
        Node *nextNode = current->next;

        // Tách current ra khỏi danh sách cũ
        current->next = nullptr;

        // Chèn current vào danh sách đã sắp xếp
        insertSorted(sortedHead, current);

        current = nextNode;
    }

    list.head = sortedHead;
    updateTail(list);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}