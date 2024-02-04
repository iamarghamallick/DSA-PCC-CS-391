#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

struct Node *createNode(int data)
{
    struct Node *nn = (struct Node *)malloc(sizeof(struct Node));
    nn->data = data;
    nn->next = NULL;
    return nn;
}

int isEmpty()
{
    return front == NULL && rear == NULL;
}

void enqueue(int data)
{
    struct Node *nn = createNode(data);
    if (isEmpty())
    {
        front = rear = nn;
        return;
    }
    rear->next = nn;
    rear = nn;
}

int dequeue()
{
    if (isEmpty())
    {
        printf("List is Empty!\n");
        return -1;
    }
    struct Node *toDelete = front;
    front = front->next;
    return toDelete->data;
}

void display()
{
    if (isEmpty())
    {
        printf("List is Empty!\n");
        exit(0);
    }
    struct Node *temp = front;
    printf("FRONT -> ");
    while (temp != rear)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d -> REAR\n", temp->data);
}

int main()
{
    // display();
    // dequeue();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();
    return 0;
}