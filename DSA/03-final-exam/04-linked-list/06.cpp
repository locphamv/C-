#include <bits/stdc++.h>
using namespace std;

struct Candidate {
    string id;
    double score;
};

struct Node {
    Candidate data;
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

Node *createNode(const Candidate &candidate) {
    Node *node = new Node;
    node->data = candidate;
    node->next = nullptr;
    return node;
}

void addLast(List &list, const Candidate &candidate) {
    Node *node = createNode(candidate);

    if (list.head == nullptr) {
        list.head = list.tail = node;
    } else {
        list.tail->next = node;
        list.tail = node;
    }
}

bool comesBefore(const Candidate &a, const Candidate &b) {
    if (a.score != b.score) {
        return a.score > b.score;
    }

    return a.id < b.id;
}

void splitList(Node *head, Node *&left, Node *&right) {
    if (head == nullptr || head->next == nullptr) {
        left = head;
        right = nullptr;
        return;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    left = head;
    right = slow->next;

    // Cắt thành hai danh sách độc lập
    slow->next = nullptr;
}

Node *mergeLists(Node *left, Node *right) {
    Node dummy{{"", 0.0}, nullptr};
    Node *tail = &dummy;

    while (left != nullptr && right != nullptr) {
        /*
        Lấy left nếu left đứng trước right
        hoặc hai phần tử tương đương.
        */
        if (!comesBefore(right->data, left->data)) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }

        tail = tail->next;
    }

    if (left != nullptr) {
        tail->next = left;
    } else {
        tail->next = right;
    }

    return dummy.next;
}

Node *mergeSort(Node *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node *left = nullptr;
    Node *right = nullptr;

    splitList(head, left, right);

    left = mergeSort(left);
    right = mergeSort(right);

    return mergeLists(left, right);
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
    cout << fixed << setprecision(1);

    Node *current = list.head;

    while (current != nullptr) {
        cout << current->data.id << ' ' << current->data.score << '\n';

        current = current->next;
    }
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
        Candidate candidate;

        cin >> candidate.id >> candidate.score;

        addLast(list, candidate);
    }

    list.head = mergeSort(list.head);
    updateTail(list);

    printList(list);
    clearList(list);

    return 0;
}