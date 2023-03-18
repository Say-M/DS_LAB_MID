#include <bits/stdc++.h>
using namespace std;

int precedence(char s)
{
    if (s == '+' || s == '-')
        return 1;
    else if (s == '*' || s == '/')
        return 2;
    else if (s == '^' || s == '↑')
        return 3;
    else
        return 0;
}

string infixToPostfix(string infix)
{
    string postfix = "";
    stack<char> stack;

    for (int i = 0; i < infix.size(); i++)
    {
        if (infix[i] == '(')
            stack.push(infix[i]);
        else if (infix[i] == ')')
        {
            while (!stack.empty() && stack.top() != '(')
            {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop();
        }
        else if (precedence(infix[i]) == 0)
            postfix += infix[i];
        else
        {
            // "+" <= "*"
            while (!stack.empty() && precedence(infix[i]) <= precedence(stack.top()))
            {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(infix[i]);
        }
    }

    while (!stack.empty())
    {
        postfix += stack.top();
        stack.pop();
    }

    return postfix;
}

int main()
{
    string infix = "(a-b/c)*(a/k-l)";
    cout << infixToPostfix(infix);
}