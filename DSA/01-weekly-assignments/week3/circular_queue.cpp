#include <iostream>
using namespace std;

struct Queue {
    int* Q;
    int front, rear;
    int size;
    int count;
};

void initQueue(Queue &q, int size) {
    q.Q = new int[size];
    q.size = size;
    q.front = 0;
    q.rear = -1;
    q.count = 0;
}

void enqueue(Queue &q, int x) {
    if (q.count == q.size) {
        cout << "Queue day\n";
        return;
    }

    q.rear = (q.rear + 1) % q.size;
    q.Q[q.rear] = x;
    q.count++;
}

int dequeue(Queue &q) 
{
    if (q.count == 0) 
    {
        cout << "Queue rong\n";
        return -1;
    }

    int x = q.Q[q.front];
    q.front = (q.front + 1) % q.size;
    q.count--;
    return x;
}


void printQueue(Queue q) {
    if (q.count == 0) {
        cout << "Queue rong\n";
        return;
    }

    int i = q.front;
    for (int k = 0; k < q.count; k++) {
        cout << q.Q[i] << " ";
        i = (i + 1) % q.size;
    }
    cout << endl;
} 

void destroyQueue(Queue &q) {
    delete[] q.Q;
    q.Q = NULL;
    q.size = 0;
    q.count = 0;
    q.front = 0;
    q.rear = -1;
}





int main() {
    Queue q;
    initQueue(q, 4);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    printQueue(q);

    dequeue(q) ;
    enqueue(q, 50);
    
    printQueue(q);

    destroyQueue(q);
    return 0;
} 