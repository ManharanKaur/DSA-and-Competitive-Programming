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

string Prefix_To_Postfix(const string &prefix)
{
    stack<string> s; // define a stack of strings

    for (int i = prefix.length() - 1; i >= 0; i--) // iterate from back
    {
        char c = prefix[i]; // character to process

        if (isalnum(c))  // if character is alphaber or number
            s.push({c}); // push it to stack (c is a character and {c} is character array which is string)

        else if (isOperator(c)) // if operator is encountered
        {
            // it is like it will make "+ab" to "ab+"
            // pop tast two elements
            string o1 = s.top();
            s.pop();
            string o2 = s.top();
            s.pop();
            // now process this with operator and push the string back to stack
            s.push(o1 + o2 + c);
        }
    }
    return s.top();
}

int main()
{
    string prefixExpr = "*-A/BC-/AKL"; // Postfix: ABC/-AK/L-*

    cout << "Prefix Expression 1: " << prefixExpr << endl;
    cout << "Postfix Expression 1: " << Prefix_To_Postfix(prefixExpr) << endl;

    return 0;
}