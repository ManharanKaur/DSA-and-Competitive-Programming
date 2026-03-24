#include <iostream>
#include <stack>
using namespace std;

class Queue
{
    stack<int> s1, s2;

public:
    void push(int x)
    {
        s1.push(x);
    }

    int front()
    {
        if (s1.empty())
            return -1;

        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int front = s2.top();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return front;
    }

    void pop()
    {
        if (s1.empty())
            return;

        while (s1.size() > 1)
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
};

int main()
{
    Queue q;
    return 0;
}