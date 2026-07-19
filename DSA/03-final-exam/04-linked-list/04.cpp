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
void init(List &l) {
    l.head = l.tail = nullptr;
}

Node *createNode(int val) {
    Node *p = new Node;
    p->data = val;
    p->next = nullptr;
    return p;
}

void addLast(List &l, int val) {
    Node *p = createNode(val);
    if (l.head == nullptr) {
        l.head = l.tail = p;
    } else {
        l.tail->next = p;
        l.tail = p;
    }
}

Node *mergeSortedLists(Node *first, Node *second) {
    Node dummy{0, nullptr};
    Node *tail = &dummy;
    while (first && second) {
        if (first->data <= second->data) {
            tail->next = first;
            first = first->next;
        } else {
            tail->next = second;
            second = second->next;
        }
        tail = tail->next;
    }
    if (first) {
        tail->next = first;
    } else {
        tail->next = second;
    }
    return dummy.next;
}
void updateTail(List &list) {
    list.tail = list.head;
    if (list.tail = nullptr) {
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
void clearList(List& list) {
    while (list.head != nullptr) {
        Node* nodeToDelete = list.head;
        list.head = list.head->next;
        delete nodeToDelete;
    }

    list.tail = nullptr;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    List firstList, secondList, result;
    init(firstList);
    init(secondList);
    init(result);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        addLast(firstList, value);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int value;
        cin >> value;
        addLast(secondList, value);
    }

    result.head = mergeSortedLists(firstList.head, secondList.head);

    updateTail(result);

    // Các node đã chuyển sang result
    firstList.head = firstList.tail = nullptr;
    secondList.head = secondList.tail = nullptr;

    printList(result);
    clearList(result);
    return 0;
}