#include <iostream>
using namespace std;

class Node
{ // to create nodes
public:
    int data;   // initiallising data to put in the node
    Node *next; // pointer to next node
    Node(int val)
    { // constructor to initialise value to node and pointing next to NULL
        this->data = val;
        this->next = nullptr;
    }
};

class Circular_Linked_List
{
private:
    Node *head;
    Node *tail;

public:
    Circular_Linked_List() : head(nullptr), tail(nullptr) {}
    void insert(int x);
    void display();
};

void Circular_Linked_List::insert(int val)
{
    Node *newnode = new Node(val);
    if (head == nullptr)
    {
        head = newnode;
        tail = newnode;
        tail->next = head;
        return;
    }
    newnode->next = tail->next;
    tail->next = newnode;
    tail = newnode;
}

void Circular_Linked_List::display()
{
    if (head == nullptr)
        return;
    Node *temp = head;
    cout << "-> ";
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "Head" << endl;
}

int main()
{
    Circular_Linked_List A;
    for (int i = 1; i < 11; i++)
    {
        A.insert(i);
    }
    A.display();
}