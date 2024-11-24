#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// function to check if the character in string is an operator or not
bool isOperator(char c)
{
    return (c == '+' || c == '^' || c == '-' || c == '*' || c == '/');
}

// function to evaluate expression
int performOperation(char op, int p1, int p2)
{
    switch (op)
    {
    case '+':
        return p1 + p2;
    case '-':
        return p1 - p2;
    case '*':
        return p1 * p2;
    case '/':
        return p1 / p2;
    case '^':
        return pow(p1,p2);
    default:
        return 0;
    }
}

int evaluation(const string &exp)
{
    stack<int> s;
    stringstream ss(exp); // string buffer. Will split the string on basis of spaces
    string Tokens;
    vector<string> T;
    while (ss >> Tokens) // putting single token from string buffer ss to 'Tokens'
    {
        T.push_back(Tokens);
    }
    for (int i = T.size() - 1; i >= 0; i--) // reverse traversing in prefix
    {
        if (isOperator(T[i][0])) // check if the token is an operator by checking 1st character of the token
        {
            if (s.size() < 2) // if size is less than 2, that means not enough operands to process
                return false;

            // get top 2 operands to operate
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            // perform operation and push result to stack
            s.push(performOperation(T[i][0], a, b));
        }
        else
        {
            // push operand to stack
            s.push(stoi(T[i]));
        }
    }
    if (s.size() ==   1) // check condition
        return s.top();
    else // Some operands or operators are left to process
        throw invalid_argument("Invalid Expression!");
}

int main()
{
    string expr = "+ * ^ 2 3 3 ^ 4 2"; // 40
    try
    {
        cout << "Answer: " << evaluation(expr) << endl;
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }

    return 0;
}