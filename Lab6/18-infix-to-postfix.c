// Infix to Postfix conversion

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

char st[MAX];
int top = -1;

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == MAX - 1;
}

void push(char data)
{
    if (isFull())
    {
        printf("Overflow\n");
        return;
    }
    st[++top] = data;
}

char pop()
{
    if (isEmpty())
    {
        printf("Underflow\n");
        return '\0';
    }
    return st[top--];
}

int isOperator(char data)
{
    return (data == '+' || data == '-' || data == '*' || data == '/' || data == '^');
}

int precedence(char data)
{
    switch (data)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

void infixToPostfix(char exp[])
{
    int n = strlen(exp);
    char output[MAX];
    int outputIndex = 0;

    push('(');

    for (int i = 0; i < n; i++)
    {
        char item = exp[i];

        if (item == '(')
            push(item);
        else if (isalpha(item))
            output[outputIndex++] = item;
        else if (isOperator(item))
        {
            while (!isEmpty() && precedence(item) <= precedence(st[top]))
            {
                output[outputIndex++] = pop();
            }
            push(item);
        }
        else if (item == ')')
        {
            while (st[top] != '(')
                output[outputIndex++] = pop();
            pop();
        }
    }

    while (!isEmpty() && st[top] != '(')
        output[outputIndex++] = pop();

    output[outputIndex] = '\0';

    printf("Postfix Expression: %s\n", output);
}

int main()
{
    char exp[] = "(A+B)*(C-D)";
    infixToPostfix(exp);
    return 0;
}
