#include <iostream>
using namespace std;

struct Queue
{
    int *Q;
    int front;
    int rear;
    int size;
};

void Init(Queue &q, int n)
{
    q.Q = new int[n];
    q.size = n;
    q.front = 0;
    q.rear = -1;
}






void Enqueue(Queue &q, int x)
{
    if (q.rear == q.size - 1)
    {
        cout << "Queue day\n";
        return;
    }
    q.rear++;
    q.Q[q.rear] = x;
}

int Dequeue(Queue &q)
{
    if (q.front > q.rear)
    {
        cout << "Queue rong\n";
        return -1;
    }
    int x = q.Q[q.front];
    q.front++;
    return x;
}








void PrintQueue(const Queue &q)
{
    for (int i = q.front; i <= q.rear; i++)
    {
        cout << q.Q[i] << " ";
    }
    cout << "\n";
}

void DestroyQueue(Queue &q)
{
    delete[] q.Q;     
    q.Q = nullptr;    
    q.front = 0;
    q.rear = -1;
    q.size = 0;
}







int main()
{
    Queue q;
    Init(q, 5);

    Enqueue(q, 10);
    Enqueue(q, 20);
    Enqueue(q, 30);

    Dequeue(q);

    PrintQueue(q);

    DestroyQueue(q);  
    return 0;
}