#include <iostream>
#include <stack>

using namespace std;

// function to find precedence of operarors
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    return 0;
}

// function to find associativity
// the associativity of +,-,*,/ is from Left to Right but ^'s is from Right to Left
// so as we want to push or pop operator from stack, we need to see associativety
// hence if + - * / are encountered whth one operator on top of stack and 2nd is of same or higher presedence,
// the first one is popped, then 2nd operator is pushed to stack
// but in case of ^, only higher presedence are popped in case of postfix
bool associativity(char op)
{
    if (op == '^') // Right to left
        return false;
    return true; // Left to right (true if presedence is to be popped)
}

// function to change infix to postfix
string Infix_to_postfix(const string &ex)
{
    stack<char> s; // character stack
    string result;

    for (char c : ex) // iterate in the expression
    {
        if (isspace(c)) // ignore the space
            continue;
        else if (isalnum(c)) // alphabet or number
            result += c;     // append to result
        else if (c == '(')
            s.push(c); // push opening bracket to stack
        else if (c == ')')
        {
            while (!s.empty() && s.top() != '(') // while top element is not opening bracket
            {
                result += s.top();
                s.pop();
            }
            // now either opening bracket is encountered or stack is empty
            if (!s.empty())
                s.pop();
        }
        else // operator
        {
            while (!s.empty() && (precedence(s.top()) > precedence(c) /*if no operator, s.top is 0*/ || associativity(c) && precedence(s.top()) == precedence(c) /*equal presedence, check associativity*/))
            {
                result += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    // append rest to string
    while (!s.empty())
    {
        result += s.top();
        s.pop();
    }
    return result;
}

int main()
{
    string infixExpr = "A/B+C*D+A^B"; // AB/CD*+AB^+
    cout << "Infix Expression : " << infixExpr << endl;
    cout << "Postfix Expression : " << Infix_to_postfix(infixExpr) << endl;

    return 0;
}