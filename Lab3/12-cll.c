#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createSLL(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = newNode;
    return newNode;
}
void addAtBeginning(struct Node **head, int value)
{
    struct Node *newNode = createSLL(value);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != *head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
    *head = newNode;
}
void addAtEnd(struct Node **head, int value)
{
    struct Node *newNode = createSLL(value);
    struct Node *curr = *head;
    while (curr->next != *head)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->next = *head;
}
void addAtIntermediate(struct Node **head, int pos, int value)
{
    if (pos == 0)
    {
        addAtBeginning(head, value);
        return;
    }
    struct Node *newNode = createSLL(value);
    struct Node *temp = *head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteFromBeginning(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is Empty!\n");
        return;
    }
    struct Node *ptr = *head;
    struct Node *temp = *head;
    while (temp->next != *head)
    {
        temp = temp->next;
    }
    temp->next = (*head)->next;
    *head = (*head)->next;
    free(ptr);
}
void deleteFromEnd(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is Empty!\n");
        return;
    }
    struct Node *temp = *head;
    while (temp->next->next != *head)
    {
        temp = temp->next;
    }
    struct Node *ptr = temp->next;
    temp->next = *head;
    free(ptr);
}
void deleteFromIntermediate(struct Node **head, int pos)
{
    struct Node *temp = *head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    struct Node *ptr = temp->next;
    temp->next = temp->next->next;
    free(ptr);
}
void displaySLL(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is Empty!\n");
        return;
    }
    struct Node *curr = head;
    printf("CURRENT CIRCULAR LINKED LIST\n\nHEAD -> ");
    while (curr->next != head)
    {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("%d -> HEAD\n\n", curr->data);
}
int main()
{
    struct Node *head = NULL;
    int choise, value, pos;
    do
    {
        printf(
            "<<== MAIN MENU ==>>\n1. Add At Beginning\n2. Add At End\n3. Display "
            "CLL\n4. Add At Intermediate\n5. Delete From Beginning\n6. Delete From "
            "End\n7. Delete From Intermediate \n0. Exit\nEnter your choise ==>> ");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &value);
            addAtBeginning(&head, value);
            displaySLL(head);
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d", &value);
            addAtEnd(&head, value);
            displaySLL(head);
            break;
        case 3:
            displaySLL(head);
            break;
        case 4:
            printf("Enter the value to be added: ");
            scanf("%d", &value);
            printf("Enter Position: ");
            scanf("%d", &pos);
            addAtIntermediate(&head, pos, value);
            displaySLL(head);
            break;
        case 5:
            deleteFromBeginning(&head);
            displaySLL(head);
            break;
        case 6:
            deleteFromEnd(&head);
            displaySLL(head);
            break;
        case 7:
            printf("Enter Position: ");
            scanf("%d", &pos);
            deleteFromIntermediate(&head, pos);
            displaySLL(head);
            break;
        case 0:
            printf("EXITING...\n");
            break;
        default:
            printf("Invalid Choise! Try Again.\n");
            break;
        }
    } while (choise != 0);
}
