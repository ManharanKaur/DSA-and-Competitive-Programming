#include <iostream>
using namespace std;


struct Node
{
    int data;
    Node * next;
    Node(int x) : data(x), next(nullptr){};
};

Node * intersecting_Node(Node* head, Node* slow, Node* fast){
    slow = head;
    while(true){
        slow = slow->next;
        fast = fast->next;
        if(slow == fast)
            break;
    }
    return slow;
}

bool Floyd_Cycle(Node* head){
    Node * slow = head; // will traerse 1 steps
    Node * fast = head; // will traverse 2 steps
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            cout << "Cycle present" << endl;
            Node* intersection = intersecting_Node( head, slow, fast);
            cout << "Intersecting node is " << intersection->data << endl;
            return true;
        }
    }
    return false;
}

int main(){
    // 1 -> 2 -> 3 -> 4 
    //           ^    |
    //           6 <- 5
    Node * head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3); // intersecting node
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = head->next->next;

    bool result = Floyd_Cycle(head);
    cout << result;
}
