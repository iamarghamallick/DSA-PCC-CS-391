#include <stdio.h>
#include <stdlib.h>
#define bool int
#define MAX 100

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int data)
{
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = data;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

struct node *insert(struct node *root, int data)
{
    struct node *nn = create(data);
    if (root == NULL)
        return nn;
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

struct node *stack[MAX];
int top = -1;

bool isEmpty()
{
    return top == -1;
}

void push(struct node *root)
{
    stack[++top] = root;
}

struct node *pop()
{
    if (!isEmpty())
        return stack[top--];
    return NULL;
}

void inOrder(struct node *root)
{
    struct node *curr = root;
    bool done = 0;
    while (!done)
    {
        if (curr != NULL)
        {
            push(curr);
            curr = curr->left;
        }
        else
        {
            if (!isEmpty())
            {
                curr = pop();
                printf("%d\t", curr->data);
                curr = curr->right;
            }
            else
                done = 1;
        }
    }
}

void preOrder(struct node *root)
{
    if (root == NULL)
        return;
    push(root);
    while (!isEmpty())
    {
        struct node *curr = pop();
        printf("%d\t", curr->data);
        if (curr->right)
            push(curr->right);
        if (curr->left)
            push(curr->left);
    }
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 4);
    root = insert(root, 1);
    root = insert(root, 11);

    inOrder(root);
    printf("\n");

    preOrder(root);
    printf("\n");

    return 0;
}