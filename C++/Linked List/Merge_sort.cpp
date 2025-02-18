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
    Node *head; // points to first element of linked list
    Node* merge_sort_util(Node*head);
    Node * findmid(Node* head);
    Node* merge(Node* left, Node* right);
public:
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
    void Insertion_At_End(int ele);
    void merge_sort(){
        head = merge_sort_util(head);
    }
};
// Traversal
// temp pointer used to traverse linked list
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


// Insertion
void Linked_List::Insertion_At_End(int ele)
{
    Node *newNode = new Node(ele);
    if (head == nullptr) // if list is empty
    {
        head = newNode;
        return;
    }
    Node *temp = head; // insertion
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

Node * Linked_List::findmid(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* Linked_List::merge(Node* left, Node* right){
    if(left == nullptr) return right;
    if(right == nullptr) return left;
    Node *dummy = new Node(-1);
    Node* temp = dummy;
    while (left != nullptr && right != nullptr){
        if(left->data < right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    if (left != nullptr) temp->next = left;
    if (right != nullptr) temp->next = right;

    Node* ans = dummy->next;
    delete dummy;
    return ans;
}
Node* Linked_List::merge_sort_util(Node*head){
    if (head == nullptr || head->next == nullptr){
        return head;
    }
    Node* mid = findmid(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = nullptr;

    left = merge_sort_util(left);
    right = merge_sort_util(right);
     
    Node*result = merge(left, right);
    return result;
}

int main()
{
    int Arr[8] = {2, 3, 1, 1, 7, 0, 1, 9};
    Linked_List L(Arr, 8);
    cout << "Linked List:\n";
    L.Display();
    cout << "Merge Sort:\n";
    L.merge_sort();
    L.Display();
}