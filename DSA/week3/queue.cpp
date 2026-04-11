#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};

void initQueue(Queue &q) 
{
    q.front = NULL;
    q.rear = NULL;
}

void enqueue(Queue &q, int x) 
{
    Node* p = new Node;
    p->data = x;
    p->next = NULL;

    if (q.front == NULL) {
        q.front = p;
        q.rear = p;
    } else {
        q.rear->next = p;
        q.rear = p;
    }
}

int dequeue(Queue &q) 
{
    if (q.front == NULL) 
    {
        cout << "Queue rong\n";
        return -1;
    }

    Node* p = q.front;
    int x = p->data;
    q.front = q.front->next;
    delete p;

    if (q.front == NULL)
    {
        q.rear = NULL;
    }
    
    return x;
}


void printQueue(Queue q) 
{
    if (q.front == NULL) 
    {
        cout << "Queue rong\n";
        return;
    }

    Node* p = q.front;
    while (p) 
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    Queue q;
    initQueue(q);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    cout << "Queue hien tai: ";
    printQueue(q);

    cout << "Lay ra: " << dequeue(q) << endl;
    cout << "Queue sau khi dequeue: ";
    printQueue(q);

    cout << "Lay ra: " << dequeue(q) << endl;
    cout << "Lay ra: " << dequeue(q) << endl;
    cout << "Lay ra: " << dequeue(q) << endl;  

    return 0;
}