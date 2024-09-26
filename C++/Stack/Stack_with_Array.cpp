#include <iostream>
using namespace std;

class Stack{
    int * stack;
    int top;
    int maxsize;
    public:
    Stack(int size){stack = new int[size];top = -1; maxsize = size;}
    bool isEmpty();
    bool isFull();
    int push(int x);
    int pop();
    int peek();
};

// function to check if stack is empty or not
bool Stack::isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}

// function to check if stack is full or not
bool Stack::isFull()
{
    if (top == maxsize - 1)
        return true;
    else
        return false;
}

// function to push element in stack
int Stack::push(int x)
{
    if (isFull()) // is sttack is full
    {
        cout << "Stack Overflow\n";
        return INT16_MIN;
    }
    top ++;
    stack[top] = x;
    return x;
}

// function to pop element in stack
int Stack::pop()
{
    if (isEmpty()) // if stack is empty
    {
        cout << "Stack Undeflow\n";
        return INT16_MIN;
    }
    int result = stack[top];
    top--;
    return result; // return deleted element
}

// function to get top element without removing it
int Stack::peek()
{
    if (isEmpty()) // if stack is empty
    {
        cout << "Stack is empty\n";
        return INT16_MIN;
    }
    else
        return stack[top]; // return valur at top
}



int main(){
    Stack s(10);
    cout << "isEmpty(): " << s.isEmpty() << endl;
    cout << "isFull(): " << s.isFull() << endl;
    cout << "peek(): " << s.peek() << endl;
    cout << endl;

    cout << "Pushing elements:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << s.push(i+1)<< " ";
    }
    cout << endl;

    cout << "isEmpty(): " << s.isEmpty() << endl;
    cout << "isFull(): " << s.isFull() << endl;
    cout << "peek(): " << s.peek() << endl;
    cout << endl;

    cout << "popping elements:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << s.pop() << " ";
    }
    cout << endl;
    
    cout << "isEmpty(): " << s.isEmpty() << endl;
    cout << "isFull(): " << s.isFull() << endl;
    cout << "peek(): " << s.peek() << endl;
    cout << endl;
}