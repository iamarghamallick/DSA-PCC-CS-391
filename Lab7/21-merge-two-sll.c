// Write a C program for merging two linked lists (SLL).

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insert(struct Node **head, int data)
{
    struct Node *nn = (struct Node *)malloc(sizeof(struct Node));
    nn->data = data;
    nn->next = NULL;
    if (*head == NULL)
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
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void mergeSLL(struct Node *head1, struct Node *head2)
{
    struct Node *temp = head2;
    while (temp != NULL)
    {
        insert(&head1, temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    insert(&head1, 10);
    insert(&head1, 20);
    insert(&head1, 30);
    insert(&head1, 40);
    insert(&head1, 50);
    display(head1);
    insert(&head2, 11);
    insert(&head2, 21);
    insert(&head2, 31);
    insert(&head2, 41);
    insert(&head2, 51);
    display(head2);
    mergeSLL(head1, head2);
    display(head1);
    return 0;
}