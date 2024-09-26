#include <iostream>
using namespace std;

// creating node
class Node
{
public:
    int data;
    Node *prev; // previous node
    Node *next; // next node
    Node(int Data)
    {
        data = Data;
        prev = nullptr; // setting previous node to NULL
        next = nullptr; // setting next node to NULL
    }
};

// creating double linked list
class LinkedListDouble
{
private:
    Node *head;
    Node *tail;

public:
    LinkedListDouble() : head(nullptr), tail(nullptr) {};
    LinkedListDouble(int arr[], int count)
    {
        // passing array to linked list
        head = tail = new Node(arr[0]);
        Node *temp = head;
        for (int i = 1; i < count; i++)
        {
            Node *newnode = new Node(arr[i]);
            temp->next = newnode;
            newnode->prev = temp;
            temp = temp->next;
            tail = temp;
        }
    }

    void display();
    void insertion_at_beginning(int);
    void insertion_at_end(int);
    void insertion_at_specific_position(int ele, int pos);
    void deletion_at_beginning();
    void deletion_at_end();
    void deletion_at_specific_position(int pos);
    void reverse();
};

// Traversal
void LinkedListDouble::display()
{
    cout << "Forward:  ";
    Node *temp = head;
    cout << "NULL <-> ";
    while (temp != nullptr)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    cout << "Backward:  ";
    temp = tail;
    cout << "NULL <-> ";
    while (temp != nullptr)
    {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

// Insertion
void LinkedListDouble::insertion_at_beginning(int ele)
{
    Node *newnode = new Node(ele);
    if (head == nullptr) // empty list
    {
        head = newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}
void LinkedListDouble::insertion_at_end(int ele)
{
    Node *newnode = new Node(ele);
    if (head == nullptr) // empty list
    {
        head = newnode;
        return;
    }
    Node *temp = tail;
    temp->next = newnode;
    newnode->prev = temp;
    tail = newnode;
}
void LinkedListDouble::insertion_at_specific_position(int ele, int pos)
{
    Node *newnode = new Node(ele);
    if (pos == 1) // position is 1
    {
        if (head == nullptr) // empty list
        {
            head = newnode;
            return;
        }
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        return;
    }
    // traverse to node just before target position
    Node *temp = head;
    for (int i = 1; i < pos; i++)
    {
        if (temp == nullptr) // position out of bound
        {
            cout << "Position out of bound";
            delete newnode;
            return;
        }
        temp = temp->next;
    }
    newnode->next = temp;
    newnode->prev = temp->prev;
    temp->prev->next = newnode;
    temp->prev = newnode;
}

// Deletion
void LinkedListDouble::deletion_at_beginning()
{
    if (head == nullptr) // empty list
        return;          // nothing to delete
    Node *temp = head;
    head = head->next;   // moving head pointer forward
    if (head != nullptr) // list has atleast 2 elements
        head->prev = nullptr;
    delete temp;
}
void LinkedListDouble::deletion_at_end()
{
    if (head == nullptr) // empty list
        return;          // nothing to delete
    Node *temp = head;
    if (head->next == nullptr) // only one element
    {
        head = head->next; // moving head pointer forward
        head->prev = nullptr;
        delete temp;
        return;
    }
    temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
}
void LinkedListDouble::deletion_at_specific_position(int pos)
{
    if (head == nullptr) // empty list
        return;
    // if position is 1
    Node *temp = head;
    if (pos == 1)
    {
        head = head->next;   // moving head pointer forward
        if (head != nullptr) // list has atleast 2 elements
            head->prev = nullptr;
        delete temp;
        return;
    }
    for (int i = 1; i < pos; i++)
    {
        if (temp == nullptr)
        {
            // position out of bound
            cout << "position out of bound\n";
            return;
        }
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

// Reverse
// Basically we are swapping next and previous pointer;
void LinkedListDouble::reverse()
{
    Node *current = head;
    while (current != nullptr)
    {
        // swapping next and prev
        Node *temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        // moving current to next node
        current = current->prev; // after swapping, next become previous thats why we use current.prev
    }
    // swapping head and tail
    current = head;
    head = tail;
    tail = current;
}

int main()
{
    int arr[8] = {2, 3, 1, 1, 7, 0, 1, 9};
    LinkedListDouble L(arr, 8);
    L.display();
    L.insertion_at_beginning(5);
    L.display();
    L.insertion_at_end(6);
    L.display();
    L.insertion_at_specific_position(8, 5);
    L.display();
    L.deletion_at_beginning();
    L.display();
    L.deletion_at_end();
    L.display();
    L.deletion_at_specific_position(4);
    L.display();
    L.reverse();
    L.display();
}