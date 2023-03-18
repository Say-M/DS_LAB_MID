#include <bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;

    return 0;
}

// Function to convert infix to postfix
string infixToPostfix(string exp)
{
    stack<char> stack;
    string postfix = "";

    for (int i = 0; i < exp.length(); i++)
    {
        // If the scanned character is an operand, add it to output.
        if (isalnum(exp[i]))
            postfix += exp[i];

        // If the scanned character is an '(', push it to the stack.
        else if (exp[i] == '(')
            stack.push('(');

        // If the scanned character is an ')', pop and output from the stack
        // until an '(' is encountered.
        else if (exp[i] == ')')
        {
            while (!stack.empty() && stack.top() != '(')
            {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop();
        }

        // If an operator is scanned
        else
        {
            // + = 1, / = 2
            while (!stack.empty() && precedence(exp[i]) <= precedence(stack.top()))
            {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(exp[i]);
        }
    }

    // pop all the operator from the stack
    while (!stack.empty())
    {
        postfix += stack.top();
        stack.pop();
    }

    return postfix;
}

int main()
{
    string exp1 = "a+b*c";
    cout << "Infix expression: " << exp1 << endl;
    cout << "Postfix expression: " << infixToPostfix(exp1) << endl
         << endl;

    string exp2 = "(a+b)*c";
    cout << "Infix expression: " << exp2 << endl;
    cout << "Postfix expression: " << infixToPostfix(exp2) << endl
         << endl;

    string exp3 = "a*b+c*d";
    cout << "Infix expression: " << exp3 << endl;
    cout << "Postfix expression: " << infixToPostfix(exp3) << endl
         << endl;

    string exp4 = "a*(b+c)*d";
    cout << "Infix expression: " << exp4 << endl;
    cout << "Postfix expression: " << infixToPostfix(exp4) << endl
         << endl;

    string exp5 = "a+b+c+d";
    cout << "Infix expression: " << exp5 << endl;
    cout << "Postfix expression: " << infixToPostfix(exp5) << endl
         << endl;

    string exp6 = "(a-b/c)*(a/k-l)";
    cout << "Infix expression: " << exp6 << endl;
    cout << "Postfix expression: " << infixToPostfix(exp6) << endl
         << endl;
    return 0;
}