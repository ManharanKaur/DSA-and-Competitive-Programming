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
};
