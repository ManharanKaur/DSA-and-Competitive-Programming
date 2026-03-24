#include <iostream>
#include <queue>
using namespace std;

class Stack
{
    queue<int> q1, q2;

public:
    void push(int x)
    {
        q1.push(x);
    }
    int top()
    {
        if (q1.empty())
            return -1;

        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int top = q1.front();
        q2.push(top);
        q1.pop();
        swap(q1, q2);
        return top;
    }
    void pop()
    {
        if (q1.empty())
            return;
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        swap(q1, q2);
    }
};

int main()
{
    Stack s;
    return 0;
}