#include <bits/stdc++.h>
using namespace std;

int isOperator(char s)
{
    if (s == '+' || s == '-' || s == '*' || s == '/' || s == '^' || s == '↑')
        return 1;
    return 0;
}

string PostfixToInfix(string postfix)
{
    stack<string> stack;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (!isOperator(postfix[i]))
        {
            string op(1, postfix[i]);
            stack.push(op);
        }
        else
        {
            string op1 = stack.top();
            stack.pop();
            string op2 = stack.top();
            stack.pop();
            stack.push('(' + op2 + postfix[i] + op1 + ')');
        }
    }
    return stack.top();
}

int main()
{
    string postfix = "ab+c-def^^*g/";
    cout << PostfixToInfix(postfix) << endl;
}