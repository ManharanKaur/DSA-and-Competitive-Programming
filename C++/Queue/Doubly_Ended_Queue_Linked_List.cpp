#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
};

class Deque
{
private:
    Node *front; // FIRST NODE : front -> a -> b -> c (where deletion occur)
    Node *rear;  // LAST NODE : a -> b -> c -> rear (where insertion occur)
    int Size;

public:
    Deque() : front(nullptr), rear(nullptr) {Size = 0;}

    // check if Queuw in empty or not
    bool isEmpty()
    {
        return front == nullptr;
    }
    // NOTE : we can increase Size of queue in linked list as long as we want No "Full" restrictions are required

    int get_Size()
    {
        return Size;
    }

    void insert_Front(int data);
    void insert_Rear(int data);
    void delete_Front();
    void delete_Rear();
    int view_Front();
    int view_Rear();
    void erase();
    void display();
};

// insert elements to front
void Deque::insert_Front(int data)
{
    // create new node
    Node *newnode = new Node(data);
    if (rear == nullptr) // empty
    {
        front = newnode;
        rear = newnode;
        return;
    }

    newnode->next = front;
    front->prev = newnode;
    front = newnode;
    Size++;
}

// insert elements to rear
void Deque::insert_Rear(int data)
{
    // create new node
    Node *newnode = new Node(data);
    if (rear == nullptr) // empty
    {
        front = newnode;
        rear = newnode;
        return;
    }

    newnode->prev = rear;
    rear->next = newnode;
    rear = newnode;
    Size++;
}

// Remove element from front
void Deque ::delete_Front()
{
    if (isEmpty())
    {
        cout << "Queue is empty \n";
        return; // no elements
    }
    Node *temp = front;
    front = front->next;
    if (front == nullptr)
        rear = nullptr;
    else
        front->prev = nullptr;
    delete temp;
    Size--;
}

// Remove element from rear
void Deque ::delete_Rear(){
if (isEmpty())
    {
        cout << "Queue is empty \n";
        return; // no elements
    }
    Node *temp = rear;
    rear = rear->prev;
    if (rear == nullptr)
        front = nullptr;
    else
        rear->next = nullptr;
    delete temp;
    Size--;
}

// view front element without removing
int Deque ::view_Front()
{
    if (isEmpty())
        return INT16_MIN;
    else
        return front->data;
}

// view rear element without removing
int Deque ::view_Rear()
{
    if (isEmpty())
        return INT16_MIN;
    else
        return rear->data;
}

// Traversal
void Deque ::display()
{
    Node *temp = front;
    cout << "NULL <- front -> ";
    while (temp != rear->next)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << " <- rear -> NULL\n";
}

int main()
{
    Deque Q;

    // Inserting elements at the front
    cout << "Inserting elements at the front:\n";
    Q.insert_Front(10);
    Q.display();

    Q.insert_Front(20);
    Q.display();

    Q.insert_Front(30);
    Q.display();

    // Inserting elements at the rear
    cout << "\nInserting elements at the rear:\n";
    Q.insert_Rear(40);
    Q.display();

    Q.insert_Rear(50);
    Q.display();

    // Viewing front and rear elements
    cout << "\nFront element: " << Q.view_Front() << endl;
    cout << "Rear element: " << Q.view_Rear() << endl;

    // Removing elements from the front
    cout << "\nRemoving elements from the front:\n";
    Q.delete_Front();
    Q.display();

    Q.delete_Front();
    Q.display();

    // Removing elements from the rear
    cout << "\nRemoving elements from the rear:\n";
    Q.delete_Rear();
    Q.display();

    Q.delete_Rear();
    Q.display();

    // Final size of the deque
    cout << "\nFinal size of the deque: " << Q.get_Size() << endl;

    // Attempting to remove from an empty deque
    cout << "\nAttempting to delete from an empty deque:\n";
    Q.delete_Front();
    Q.delete_Rear();

    return 0;
}
