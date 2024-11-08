#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

bool isOperator(char c)
{
    return (c == '+' || c == '^' || c == '-' || c == '*' || c == '/');
}

bool isPostfix(const string &exp)
{
    stack<char> Stack;
    for (int i = 0; i < exp.length(); i++)
    {
        if (isalpha(exp[i]))
            Stack.push(exp[i]); // if operand is encountered, push it into stack
        else if (isOperator(exp[i]))
        {
            if (Stack.size() >= 2) // if operator is encountered,first check size of stack
                Stack.pop();       // pop 1 element because we are only checking validation so no need of computations
            else
                return false; // if size  < 2, expression has not enough operands, hence invalid
        }
    }
    if (Stack.size() == 1) // only one term should be left in stack
        return true;
    else
        return false;
}

int main()
{
    string expression = "ABC+*";
    bool result = isPostfix(expression);
    if (result)
        cout << "Valid postfix expression.\n";
    else
        cout << "Not a valid postfix expression.\n";

    return 0;
}