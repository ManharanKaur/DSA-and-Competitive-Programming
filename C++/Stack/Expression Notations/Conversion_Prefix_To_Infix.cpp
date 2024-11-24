#include <iostream>
#include <stack>
using namespace std;

// function to check if the character in string is an operator or not
bool isOperator(char c)
{
    return (c == '+' || c == '^' || c == '-' || c == '*' || c == '/');
}

string Prefix_To_Infix(const string &prefix)
{
    stack<string> s;

    for (int i = prefix.length() - 1; i >= 0; i--) //Reverse Traversal in Postfix
    {
        char c = prefix[i]; // process a character

        if (isalnum(c)) 
        {
            // if c is alphanumeric, push it to stack
            s.push({c});
        }
        else if (isOperator(c))
        {
            // if operator is encountered, pop top 2 elements
            string operand1 = s.top();
            s.pop();
            string operand2 = s.top();
            s.pop();
            // process the 2 elements ie +ab to (a+b)
            s.push("(" + operand1 + c + operand2 + ")");
        }
    }
    return s.top();
}

int main()
{
    string prefixExpr = "*-A/BC-/AKL"; // Infix: ((A - (B / C)) * ((A / K) - L))

    cout << "Prefix Expression : " << prefixExpr << endl;
    cout << "Infix Expression : " << Prefix_To_Infix(prefixExpr) << endl;

    return 0;
}