#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};

class Queue
{
private:
    Node *front; // FIRST NODE : front -> a -> b -> c (where deletion occur)
    Node *rear;  // LAST NODE : a -> b -> c -> rear (where insertion occur)
    int maxsize;
    int currentsize;

public:
    Queue(int size) : front(nullptr), rear(nullptr), maxsize(size), currentsize(0) {}

    // check if Queuw in empty or not
    bool isEmpty()
    {
        return currentsize == 0;
    }

    // check if Queue is full
    // NOTE : we can increase size of queue in linked list as long as we want No "Full" restrictions are required
    bool isFull()
    {
        return currentsize == maxsize;
    }

    // insert elements to rear
    void Enqueue(int data)
    {
        if (isFull()){
            cout << "Queue is full\n";
            return; // cant add more elements
            }
        // create new node
        Node *newnode = new Node(data);
        if (rear == nullptr)
        {
            front = newnode;
            rear = newnode;
            return;
        }

        rear->next = newnode;
        rear = newnode;
        currentsize++;
    }

    // Remove element fron front
    void Dequeue()
    {
        if (isEmpty()){
            cout << "Stack is empty \n";
            return; // no elements
            }
        Node *temp = front;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        currentsize--;
        delete temp;
    }

    // view front element without removing
    int view_front()
    {
        if (isEmpty())
            return INT16_MIN;
        else
            return front->data;
    }

    // view rear element without removing
    int view_rear()
    {
        if (isEmpty())
            return INT16_MIN;
        else
            return rear->data;
    }

    //Traversal
    void display(){
        Node * temp = front;
        cout << "front -> ";
        while (temp != rear->next)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
        
    }
};


int main(){
    int arr[] = {1,3,5,7,9,11,13,15,17,19};
    Queue Q(9);

    for (int i = 0; i < 10; i++)
    {
        Q.Enqueue(arr[i]);
    }
    Q.display();

    cout << "Try to add more elements:\n";
    Q.Enqueue(6);

    cout << "Dequeue some elements.\n";
    for (int i = 0; i < 5; i++)
    {
        Q.Dequeue();
    }
    Q.display();


}