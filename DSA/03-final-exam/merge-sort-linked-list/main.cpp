#include <iostream>
#include <string>
using namespace std;

struct SanPham {
    string maSP;
    string tenSP;
    long long giaBan;
};

struct Node {
    SanPham data;
    Node *next;
};

struct List {
    Node *head;
    Node *tail;
};

void khoiTao(List &l) {
    l.head = nullptr;
    l.tail = nullptr;
}

Node *taoNode(SanPham x) {
    Node *p = new Node;
    p->data = x;
    p->next = nullptr;
    return p;
}

void themCuoi(List &l, SanPham x) {
    Node *p = taoNode(x);

    if (l.head == nullptr) {
        l.head = l.tail = p;
    } else {
        l.tail->next = p;
        l.tail = p;
    }
}

// Trả về true nếu sản phẩm a cần đứng trước hoặc bằng sản phẩm b
bool dungThuTu(SanPham a, SanPham b) {
    if (a.giaBan < b.giaBan)
        return true;

    if (a.giaBan > b.giaBan)
        return false;

    return a.maSP <= b.maSP;
}

// Chia danh sách thành 2 nửa
void chiaDanhSach(Node *head, Node *&left, Node *&right) {
    if (head == nullptr || head->next == nullptr) {
        left = head;
        right = nullptr;
        return;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != nullptr) {
        fast = fast->next;

        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    left = head;
    right = slow->next;

    slow->next = nullptr;
}

// Trộn 2 danh sách đã được sắp xếp
Node *tronHaiDanhSach(Node *left, Node *right) {
    if (left == nullptr)
        return right;

    if (right == nullptr)
        return left;

    Node *result = nullptr;

    if (dungThuTu(left->data, right->data)) {
        result = left;
        result->next = tronHaiDanhSach(left->next, right);
    } else {
        result = right;
        result->next = tronHaiDanhSach(left, right->next);
    }

    return result;
}

// Merge Sort danh sách liên kết đơn
void mergeSort(Node *&head) {
    if (head == nullptr || head->next == nullptr)
        return;

    Node *left = nullptr;
    Node *right = nullptr;

    chiaDanhSach(head, left, right);

    mergeSort(left);
    mergeSort(right);

    head = tronHaiDanhSach(left, right);
}

void capNhatTail(List &l) {
    l.tail = l.head;

    if (l.tail == nullptr)
        return;

    while (l.tail->next != nullptr)
        l.tail = l.tail->next;
}

void xuatDanhSach(List l) {
    Node *p = l.head;

    while (p != nullptr) {
        cout << p->data.maSP << " " << p->data.tenSP << " " << p->data.giaBan << '\n';

        p = p->next;
    }
}

void giaiPhongDanhSach(List &l) {
    while (l.head != nullptr) {
        Node *p = l.head;
        l.head = l.head->next;
        delete p;
    }

    l.tail = nullptr;
}

int main() {
    List l;
    khoiTao(l);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        SanPham x;

        cin >> x.maSP;
        cin >> x.tenSP;
        cin >> x.giaBan;

        themCuoi(l, x);
    }

    mergeSort(l.head);

    // Sau khi sắp xếp, vị trí tail có thể đã thay đổi
    capNhatTail(l);

    xuatDanhSach(l);

    giaiPhongDanhSach(l);

    return 0;
}