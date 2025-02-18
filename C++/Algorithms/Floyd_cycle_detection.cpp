// Floyd cycle detection
// How it work
// 1. We use two pointers, one is slow and one is fast
// 2. If there is a cycle, the fast pointer will eventually catch up to the slow
// 3. If there is no cycle, the fast pointer will reach the end of the list
// 4. Once they catch up, we reset the slow pointer to the start and move both pointers one step at a time
// 5. Now, they will meet ar starting point of cycle

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
