#include <iostream>
using namespace std;

class Queue
{
public:
    int front, rear, maxsize;
    int *q;

    Queue(int s) : front(-1), rear(-1), maxsize(s), q(new int[s]) {}

    bool isEmpty();
    bool isFull();
    void Enqueue(int);
    void Dequeue();
    int view_front();
    int view_rear();
};

// to check underflow condition
bool Queue::isEmpty()
{
    return front == -1 && rear == -1;
}

// to check overflow condition
bool Queue::isFull()
{
    return front == (rear + 1) % maxsize;
}

// to insert an element
void Queue ::Enqueue(int data)
{
    if (isFull())
    {
        cout << "Queue is full.\n";
        return;
    }
    q[++rear] = data; // move rear pointer and add element
    if (front == -1)  // empty queue, give front to first element
        front = 0;
    return;
}

// to delate an element
void Queue ::Dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty.\n";
        return;
    }
    for (int i = 0; i < rear; i++) // delete first element by shifting array to left
        q[i] = q[i + 1];

    rear--;         // move rear pointer
    if (rear == -1) // empty queue? set back front pointer to -1
        front = -1;
}

// to view front element without removing it
int Queue ::view_front()
{
    if (isEmpty())
    {
        cout << "Queue is empty.\n";
        return -1;
    }
    return q[front];
}

// to view rear element without removing it
int Queue ::view_rear()
{
    if (isEmpty())
    {
        cout << "Queue is empty.\n";
        return -1;
    }
    return q[rear];
}

int main()
{
    // Define an array of elements to add to the queue
    int elements[] = {10, 20, 30, 40, 50};
    int size = sizeof(elements) / sizeof(int);

    // Create a queue with a maximum size of 5
    Queue queue(size);

    // Enqueue elements from the array
    cout << "Enqueuing elements:\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Enqueueing: " << elements[i] << endl;
        queue.Enqueue(elements[i]);
    }

    // Check if the queue is full
    cout << "Is the queue full? " << (queue.isFull() ? "Yes" : "No") << endl;

    // View the front and rear elements
    cout << "Front element: " << queue.view_front() << endl;
    cout << "Rear element: " << queue.view_rear() << endl;

    // Dequeue elements
    cout << "\nDequeuing elements:\n";
    while (!queue.isEmpty())
    {
        cout << "Dequeuing: " << queue.view_front() << endl;
        queue.Dequeue();
    }

    // Check if the queue is empty
    cout << "Is the queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
