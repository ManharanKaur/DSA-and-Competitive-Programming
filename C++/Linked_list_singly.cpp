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

class Linked_List // to manage nodes
{
private:
    Node *head; // points to first element of linked list
public:
    Linked_List();
    // can also initialise as Linked_List() : head(nullptr);
    Linked_List(int arr[], int count)
    {
        head = new Node(arr[0]); // setting 1st element of array to head
        Node *temp = head;       // for now temp is pointing to arr[0]
        for (int i = 1; i < count; i++)
        {
            temp->next = new Node(arr[i]); // arr[0] da next arr[1] nu point krega
            temp = temp->next;             // temp arr[0] to uth ke arr[1] tet aa jayega
        }
    }
    void Display();
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
        cout << temp->data << " ";
        temp = temp->next; // next element
    }
}

int main()
{
    int Arr[8] = {2, 3, 1, 1, 7, 0, 1, 9};
    Linked_List L(Arr, 8);
    L.Display();
}
