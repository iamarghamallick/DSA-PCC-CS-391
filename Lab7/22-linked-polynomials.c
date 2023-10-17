// Write a C program for linked representation of polynomials and also perform addition, subtraction of two polynomials

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coef;
    int expo;
    struct Node *next;
};

struct Node *createNode(int coef, int expo)
{
    struct Node *nn = (struct Node *)malloc(sizeof(struct Node));
    nn->coef = coef;
    nn->expo = expo;
    nn->next = NULL;
    return nn;
}

void createExp(struct Node **head, int coef, int expo)
{
    struct Node *nn = createNode(coef, expo);
    if ((*head) == NULL)
    {
        *head = nn;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }
}

void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("(%dx^%d) + ", temp->coef, temp->expo);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *poly1Head = NULL;
    struct Node *poly2Head = NULL;
    createExp(&poly1Head, -1, 1);
    createExp(&poly1Head, 2, 2);
    createExp(&poly1Head, 3, 3);
    display(poly1Head);
    return 0;
}