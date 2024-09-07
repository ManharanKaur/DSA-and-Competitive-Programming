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

// creating linked list
class Linked_List // to manage nodes
{
private:
    Node *head; // points to first element of linked list
public:
    Linked_List();
    // can also initialise as Linked_List() : head(nullptr) {};
    Linked_List(int arr[], int count)
    {
        // passing array to linked list
        head = new Node(arr[0]); // setting 1st element of array to head
        Node *temp = head;       // for now temp is pointing to arr[0]
        for (int i = 1; i < count; i++)
        {
            temp->next = new Node(arr[i]); // arr[0] da next arr[1] nu point krega
            temp = temp->next;             // temp arr[0] to uth ke arr[1] tet aa jayega
        }
    }
    void Display();
    bool Searching(int key);
    int Length();
    void Insertion_At_Beginning(int ele);
    void Insertion_At_End(int ele);
    void Insertion_At_Specific_position(int pos, int ele);
    void Deletion_At_Beginning();
    void Deletion_At_End();
    void Deletion_At_Specific_position(int pos);
};

Linked_List::Linked_List()
{
    head = nullptr;
    // if linked list is empty, head will point toward null pointer
}

// Traversal
void Linked_List::Display()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next; // next element
    }
    cout << "nullptr" << endl;
}

// Searching
bool Linked_List::Searching(int key)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Finding length
int Linked_List::Length()
{
    // traverse and count
    Node *temp = head;
    int l = 0;
    while (temp != nullptr)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

// Insertion
void Linked_List::Insertion_At_Beginning(int ele)
{
    Node *newNode = new Node(ele);
    newNode->next = head;
    head = newNode;
}
void Linked_List::Insertion_At_End(int ele)
{
    Node *newNode = new Node(ele);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}
void Linked_List::Insertion_At_Specific_position(int pos, int ele)
{
    Node *newNode = new Node(ele);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    if (pos == 1) // insertion at head
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node *temp = head;
    for (int i = 1; i < pos; i++)
    {
        if (temp == nullptr)
        {
            cout << "Invalid position\n";
            delete newNode;
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Deletion
void Linked_List::Deletion_At_Beginning()
{
    if (head == nullptr)
        return;
    Node *temp = head;
    head = temp->next;
    delete temp;
}
void Linked_List::Deletion_At_End()
{
    if (head == nullptr)
        return;
    if (head->next == nullptr)
    {
        delete head;
        return;
    }
    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}
void Linked_List::Deletion_At_Specific_position(int pos)
{
    if (head == nullptr)
        return;
    Node *temp = head;
    if (pos == 1)
    {
        head = temp->next;
        delete temp;
        return;
    }
    for (int i = 1; i < pos - 1 && temp != nullptr; i++)
        temp = temp->next;
    if (temp == nullptr || temp->next == nullptr)
        return;
    Node *T1 = temp->next;
    temp->next = T1->next;
    delete T1;
}


int main()
{
    int Arr[8] = {2, 3, 1, 1, 7, 0, 1, 9};
    Linked_List L(Arr, 8);
    cout << "Linked List:\n";
    L.Display();
    bool x = L.Searching(7);
    if (x == true)
        cout << "Element is present\n";
    else
        cout << "Element is NOT present\n";
    int length = L.Length();
    cout << "Length: " << length << endl;
    cout << "Insertion at beginning:\n";
    L.Insertion_At_Beginning(5);
    L.Display();
    cout << "Insertion at end:\n";
    L.Insertion_At_End(7);
    L.Display();
    cout << "Insertion at specific position:\n";
    L.Insertion_At_Specific_position(5, 9);
    L.Display();
    cout << "Deletion at beginning:\n";
    L.Deletion_At_Beginning();
    L.Display();
    cout << "Deletion at end:\n";
    L.Deletion_At_End();
    L.Display();
    cout << "Deletion at specific position:\n";
    L.Deletion_At_Specific_position(5);
    L.Display();
}