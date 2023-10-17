#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *top;
};

struct Node *create(int value)
{
    struct Node *nn = (struct Node *)malloc(sizeof(struct Node));
    nn->data = value;
    nn->next = NULL;
    return nn;
}

int isEmpty(struct Stack *stack)
{
    if (stack->top == NULL)
    {
        return 1;
    }
    return 0;
}

void push(struct Stack *stack, int data)
{
    struct Node *nn = create(data);
    nn->next = stack->top;
    stack->top = nn;
}

void pop(struct Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }
    struct Node *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
}

int peek(struct Stack *stack) { return stack->top->data; }

void display(struct Stack *stack)
{
    struct Node *temp = stack->top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(void)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = NULL;
    int choise, value;
    printf("Welcome to my STACK\n");
    int run = 1;
    do
    {
        printf("1. PUSH\n2. POP\n3. PEEK\n4. isEmpty\n0. EXIT\nEnter "
               "the choise: ");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push(stack, value);
            display(stack);
            break;
        case 2:
            pop(stack);
            display(stack);
            break;
        case 3:
            printf("%d \n", peek(stack));
            break;
        case 4:
            if (isEmpty(stack) == 1)
            {
                printf("Stack is Empty\n");
            }
            else
            {
                printf("Stack is Not Empty\n");
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
    return 0;
}