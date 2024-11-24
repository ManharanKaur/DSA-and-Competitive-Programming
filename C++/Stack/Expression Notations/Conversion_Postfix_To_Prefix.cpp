#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

// function to check if the character in string is an operator or not
bool isOperator(char c)
{
    return (c == '+' || c == '^' || c == '-' || c == '*' || c == '/');
}

string Postfix_To_Prefix(const string &postfix)
{
    stack<string> s; // define a stack of strings

    for (int i = 0; i < postfix.length(); i++) // iterate from back
    {
        char c = postfix[i]; // character to process

        if (isalnum(c))  // if character is alphaber or number
            s.push({c}); // push it to stack (c is a character and {c} is character array which is string)

        else if (isOperator(c)) // if operator is encountered
        {
            // it is like it will make "ab-" to "-ab"
            // pop tast two elements
            string o2 = s.top();
            s.pop();
            string o1 = s.top();
            s.pop();
            // now process this with operator and push the string back to stack
            s.push(c + o1 + o2);
        }
    }
    return s.top();
}

int main()
{
    string postfixExpr = "ABC/-AK/L-*";  // Prefix: *-A/BC-/AKL

    cout << "Prefix Expression 1: " << postfixExpr << endl;
    cout << "Postfix Expression 1: " << Postfix_To_Prefix(postfixExpr) << endl;

    return 0;
}