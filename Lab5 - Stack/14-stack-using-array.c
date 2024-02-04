#include <stdio.h>
#define MAX 100
int stack[MAX], top = -1;

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

void push(int data)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }
    top++;
    stack[top] = data;
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
        return;
    }
    top--;
}

int peek()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
        return -1;
    }
    return stack[top];
}

void display()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    int choise, value;
    printf("Welcome to my STACK\n");
    int run = 1;
    do
    {
        printf("1. PUSH\n2. POP\n3. PEEK\n4. isEmpty\n5. isFull\n0. EXIT\nEnter "
               "the choise: ");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push(value);
            display();
            break;
        case 2:
            pop();
            display();
            break;
        case 3:
            printf("%d \n", peek());
            break;
        case 4:
            if (isEmpty() == 1)
            {
                printf("Stack is Empty\n");
            }
            else
            {
                printf("Stack is Not Empty\n");
            }
            break;
        case 5:
            if (isFull() == 1)
            {
                printf("Stack is Full\n");
            }
            else
            {
                printf("Stack is Not Full\n");
            }
            break;
        case 0:
            run = 0;
            printf("EXITING ...\n");
            break;
        default:
            printf("Invalid Choise. Please Try Again!\n");
            break;
        }
    } while (run == 1);
}