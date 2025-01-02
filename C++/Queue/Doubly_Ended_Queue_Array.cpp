#include <iostream>
using namespace std;

class Deque
{
    int *A;
    int front;
    int rear;
    int size;

public:
    Deque(int n) : size(n), front(-1), rear(-1)
    {
        A = new int[size];
    }

    // Check if deque is full
    bool isFull()
    {
        return (front == 0 && rear == size - 1) || (front == rear + 1);
    }

    // Check if deque is empty
    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }

    // Insert at the front
    void insert_Front(int data)
    {
        if (isFull())
        {
            cout << "Deque is full\n";
            return;
        }
        if (front == -1) // empty 
            front = rear = 0;
        else // moving front pointer to previous position
            front = (front + size - 1) % size;
        A[front] = data;
    }

    // Insert at the rear
    void insert_Rear(int data)
    {
        if (isFull())
        {
            cout << "Deque is full\n";
            return;
        }
        if (front == -1)
            front = rear = 0;
        else  // move rear pointer to next position
            rear = (rear + 1) % size;
        A[rear] = data;
    }

    // Delete from the front
    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty\n";
            return;
        }
        if (front == rear) // only one element
            front = rear = -1;
        else // move front pointer to next position
            front = (front + 1) % size;
    }

    // Delete from the rear
    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty\n";
            return;
        }
        if (front == rear) // 
            front = rear = -1;
        else // move rear pointer to previous position
            rear = (rear + size - 1) % size;
    }

    // Get the front element
    int getFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty\n";
            return -1;
        }
        return A[front];
    }

    // Get the rear element
    int getRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty\n";
            return -1;
        }
        return A[rear];
    }
};

int main()
{
    Deque dq(5);

    dq.insert_Rear(10);
    dq.insert_Rear(20);
    dq.insert_Front(5);

    cout << "Front: " << dq.getFront() << "\n";
    cout << "Rear: " << dq.getRear() << "\n";

    dq.deleteFront();
    cout << "Front after deletion: " << dq.getFront() << "\n";

    dq.deleteRear();
    cout << "Rear after deletion: " << dq.getRear() << "\n";

    return 0;
}
