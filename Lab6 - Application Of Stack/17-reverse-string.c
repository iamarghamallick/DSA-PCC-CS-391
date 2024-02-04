// Reverse a string using stack

#include <stdio.h>
#define MAX 100

char st[MAX];
int top = -1;

int isEmpty()
{
    if (top == -1)
        return 1;
    return 0;
}

int isFull()
{
    if (top == MAX - 1)
        return 1;
    return 0;
}

void push(char data)
{
    if (isFull() == 1)
    {
        printf("Overflow\n");
        return;
    }
    top++;
    st[top] = data;
}

char pop()
{
    if (isEmpty() == 1)
    {
        printf("Underflow\n");
        return '\0';
    }
    return st[top--];
}

int main()
{
    int n = 5;
    char str[] = "HELLO";
    for (int i = 0; i < n; i++)
        push(str[i]);
    for (int i = 0; i < n; i++)
        printf("%c", pop());
    return 0;
}