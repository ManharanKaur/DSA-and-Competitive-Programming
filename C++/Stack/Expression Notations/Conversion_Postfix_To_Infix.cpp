#include <iostream>
#include <stack>
using namespace std;

// function to check if the character in string is an operator or not
bool isOperator(char c)
{
    return (c == '+' || c == '^' || c == '-' || c == '*' || c == '/');
}

string Postfix_To_Infix(const string &postfix)
{
    stack<string> s;

    for (int i = 0; i < postfix.length(); i++) 
    {
        char c = postfix[i]; // process a character

        if (isalnum(c)) 
        {
            // if c is alphanumeric, push it to stack
            s.push({c});
        }
        else if (isOperator(c))
        {
            // if operator is encountered, pop top 2 elements
            string operand2 = s.top();
            s.pop();
            string operand1 = s.top();
            s.pop();
            // process the 2 elements ie ab+ to (a+b)
            s.push("(" + operand1 + c + operand2 + ")");
        }
    }
    return s.top();
}

int main()
{
    string postfixExpr = "ABC/-AK/L-*"; // Infix: ((A - (B / C)) * ((A / K) - L))

    cout << "Postfix Expression : " << postfixExpr << endl;
    cout << "Infix Expression : " << Postfix_To_Infix(postfixExpr) << endl;

    return 0;
}